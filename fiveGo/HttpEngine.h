#ifndef HTTPSERVER_H
#define HTTPSERVER_H
#include<QObject>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>
#include<QJsonArray>
#include<QTimer>
#include<QEventLoop>
#include<QThread>
#include<QDebug>
#include<QSettings>
#include<queue>
#include<map>
#include<QMutex>
#include <QHostAddress>
#include "QtWebApp/requesthandler.h"
#include "QtWebApp/httpserver/httplistener.h"
#include "QtWebApp/logging/filelogger.h"

using namespace stefanfrings;
class HttpServer : public QObject
{
	Q_OBJECT
public:
	HttpServer();
	~HttpServer();
	int start();
	void stop();
	void setPort(int);
	void setIP(QString);
	static HttpServer& GetInst();
	HttpListener *server;
	RequestHandler *request;
signals:

private:
	QSettings* settings;
	
	int port;
	QString ip;
};
typedef enum _httpType
{
	JSON,
	x_www_form_urlencoded,

}httpType;
/*
	http请求引擎类 
	注意!!!
	在线程中使用时应在线程中进行声明
	主线程声明而在支线程中使用会出现下述警告，可能会出现不可预知的错误
	QObject: Cannot create children for a parent that is in a different thread.
	(Parent is QNetworkAccessManager(0x26da2e841e0), parent's thread is QThread(0x26da2e6b2e0), current thread is QThread(0x26da2eaa7b0)
*/
class HttpEngine : public QObject
{
	Q_OBJECT
public:
	HttpEngine();
	~HttpEngine();
	QString err_msg;
	/*
	根据url建立post请求阻塞线程直到获取数据或超时
	@url http地址
	@input 输入参数QJsonObject格式
	@ouput 服务器返回信息QByteArray格式 根据返回类型自行解析
	@timeOut 单位ms 超时参数 超过指定时间未获取到返回信息则报错
	*/
	bool postUrl(const QString &url, const QJsonObject &input, QByteArray &output, httpType type = httpType::JSON, int timeOut = 3000);
	/*
	根据url建立get请求阻塞线程直到获取数据或超时
	@url http地址 参数应拼接到url地址中
	@ouput 服务器返回信息QJsonObject格式
	@timeOut 单位ms 超时参数 超过指定时间未获取到返回信息则报错
	*/
	bool getUrl(const QString &url, QByteArray &output, int timeOut = 3000);
private:
	//请求句柄
	QNetworkAccessManager *manager;  
};
#endif
