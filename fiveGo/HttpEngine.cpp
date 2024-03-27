#include "HttpEngine.h"

HttpEngine::HttpEngine()
{
	manager = new QNetworkAccessManager(this);
}


HttpEngine::~HttpEngine()
{
	manager->deleteLater();
	manager = nullptr;
}

bool HttpEngine::postUrl(const QString & url, const QJsonObject & input, QByteArray &output, httpType type, int timeOut)
{
	//设置超时处理定时器
	QTimer timer;
	timer.setInterval(timeOut);
	timer.setSingleShot(true);//单次触发
	QNetworkReply *reply;
	QByteArray dataArray;
	QNetworkRequest request;
	switch (type)
	{
	case httpType::JSON: //发送Json格式数据
	{
		// 根据Json构造数据
		QJsonDocument document;
		document.setObject(input);
		dataArray = document.toJson(QJsonDocument::Compact);
        qDebug() << " post msg :" << QString(dataArray).toLocal8Bit().data();
		// 构造请求Json格式数据
		request.setUrl(QUrl(url));
		request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
		break;
	}
	case httpType::x_www_form_urlencoded: //按x_www_form_urlencoded构造数据
	{
		QStringList list;
		for (auto &value : input.toVariantMap().toStdMap())
		{
		
			QString data = QString("%1=%2").arg(value.first).arg(value.second.toString());
			list.append(data);

		}
		dataArray.append(list.join("&"));
		// 构造请求数据
		request.setUrl(QUrl(url));
		request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
		break;
	}
	default:
		return false;
		break;
	}
	
	// 发送请求
	reply = manager->post(request, dataArray);
	if (reply->error() != QNetworkReply::NoError)
	{
		err_msg = reply->errorString();
		reply->deleteLater();
		return false;
	}
	//启动事件循环等待相应
	QEventLoop eventLoop;
	connect(&timer, &QTimer::timeout, &eventLoop, &QEventLoop::quit);
	connect(manager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);

	//启动定时器
	timer.start();
	eventLoop.exec();//启动事件循环
	//定时器激活状态,处理响应
	if (timer.isActive())
	{
		timer.stop();//停止定时器
		//http请求出错，进行错误处理
		if (reply->error() != QNetworkReply::NoError) 
		{
			err_msg = reply->errorString();
			err_msg.append(reply->readAll());
			reply->deleteLater();
			return false;
		}
		else
		{
			//读取数据
			output = reply->readAll();
			return true;
		}
	}
	else//超时处理
	{
		disconnect(manager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
		reply->abort();//关闭所有连接
		err_msg = QString("connect time out !!!");
		return false;
	}
	return false;
}

bool HttpEngine::getUrl(const QString & url, QByteArray &output, int timeOut)
{
	//设置超时处理定时器
	QTimer timer;
	timer.setInterval(timeOut);
	timer.setSingleShot(true);//单次触发
	// 构造请求url
	QNetworkRequest request;
	request.setUrl(QUrl(url));
    //qDebug() << "get rul:" << url;
	// 发送请求
	QNetworkReply *reply = manager->get(request);

	//启动事件循环等待相应
	QEventLoop eventLoop;
	connect(&timer, &QTimer::timeout, &eventLoop, &QEventLoop::quit);
	connect(manager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);

	//启动定时器
	timer.start();
	eventLoop.exec();//启动事件循环
	//定时器激活状态,处理响应
	if (timer.isActive())
	{
		timer.stop();//停止定时器
		//http请求出错，进行错误处理
		if (reply->error() != QNetworkReply::NoError) 
		{
			err_msg = reply->errorString();
			reply->deleteLater();
			return false;
		}
		else
		{
			//读取数据
			output = reply->readAll();
			return true;
		}
	}
	else//超时处理
	{
		disconnect(manager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
		reply->abort();//关闭所有连接
		err_msg = QString("connect time out !!!");
		return false;
	}
	return false;
}



HttpServer::HttpServer()
{
	this->settings = new QSettings("", QSettings::IniFormat);
	//settings->setValue("port", "192.168.0.1");		//端口号
	//settings->setValue("host", "8080");           //ip
    settings->setValue("minThreads", "50");	//始终保持运行的线程数量，用来确保一段时间不活动后的良好响应时间。
    settings->setValue("maxThreads", "500");//QtWebApp可以同时处理多个http请求，该参数指定并发工作线程的最大数量。
	settings->setValue("cleanupInterval", "6000");//每隔一个cleanupInterval时间间隔（以毫秒为单位），服务器都将关闭一个空闲线程。
	settings->setValue("readTimeout", "60000");//设置通过打开大量连接而不使用它们，来保护服务器免受简单的拒绝服务攻击。静默连接将在设定的毫秒数后被关闭。
    settings->setValue("maxRequestSize", "9999999");//保护服务器免受非常多的HTTP请求而导致内存过载的影响。此值适用于常规请求。
	settings->setValue("maxMultiPartSize", "10000000");//适用于网络浏览器将文件上传到服务器时发生的大部分请求。如果要接受10 MB的文件，由于HTTP协议开销，必须将此值设置得更大一些。
}


HttpServer::~HttpServer()
{
	settings->deleteLater();
	settings = nullptr;
}

int HttpServer::start()
{
	settings->setValue("port", port);		//端口号
	settings->setValue("host", ip); //ip
	request = new RequestHandler(this);
	server = new HttpListener(settings, request, this);
	if (!server->isListening())
	{
        QString value = QString(u8"服务器开启失败:%1").arg(server->errorString());
		return 0;
	}
	return 1;
}

void HttpServer::stop()
{
	if (server->isListening())
	{
		server->close();
		delete request;
		delete server;	
		request = nullptr;
		server = nullptr;
	}
}

void HttpServer::setPort(int value)
{
	this->port = value;
}

void HttpServer::setIP(QString value)
{
	this->ip = value;
}

HttpServer& HttpServer::GetInst()
{
	static HttpServer hs;
	return hs;
}

