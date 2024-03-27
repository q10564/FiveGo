/**
  @file
  @author Stefan Frings
*/

#include <QtWebApp/logging/filelogger.h>
#include "requesthandler.h"

RequestHandler::RequestHandler(QObject* parent)
	:HttpRequestHandler(parent)
{
	qDebug("RequestHandler: created");
	qRegisterMetaType<MyPoint>("MyPoint");
}


RequestHandler::~RequestHandler()
{
	qDebug("RequestHandler: deleted");
}

void RequestHandler::service(HttpRequest& request, HttpResponse& response)
{
	qDebug("Conroller: path=%s", request.getPath().data());
	if (request.getMethod() == "GET")
	{
		// Set a response header
		response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");

		// Return a simple HTML document
		response.write("<html><body>Hello World!</body></html>", true);

		qDebug("RequestHandler: finished request");
	}
	else if (request.getMethod() == "POST")
	{
		QJsonObject json = QJsonDocument::fromJson(request.getBody()).object();
		auto m = json.toVariantMap();
		QJsonObject data;
		QString path = request.getPath().data();
        auto ip = request.getPeerAddress();//客户端IP地址
		//地址分发
		if (path == "/fiveGo/chess")
		{
			emit sendPoint(MyPoint(json["x"].toInt(), json["y"].toInt()));
		}
		else if (path == "/fiveGo/start")
		{
			emit getStart(ip.toString());
		}
		else if (path == "/fiveGo/startRes")
		{
			emit getStartRes(json["res"].toBool());
			
		}
		else if (path == "/fiveGo/msg")
		{
			emit getMsg(json["msg"].toString());
		}
		else
		{
			data.insert("code", 1001);
			data.insert("msg", u8"接受失败");
		}
		data.insert("code", 1000);
		data.insert("msg", u8"接受成功");
		QJsonDocument document;
		document.setObject(data);
		QByteArray dataArray = document.toJson(QJsonDocument::Compact);
		response.setHeader("Content-Type", "application/json; charset=UTF-8");
		response.write(dataArray);
	}

}
