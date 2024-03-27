#include "fiveGo.h"
#include <QHostAddress>
#include <QHostInfo>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDateTime>
#include <QFileDialog>
#include <QCryptographicHash>
fiveGo::fiveGo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//通过遍历获取到本机ip
	QHostInfo info = QHostInfo::fromName(QHostInfo::localHostName());
	foreach(QHostAddress address, info.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol)
		{
			//输出本地IPV4的地址 多个地址显示最后一个
			ui.lineEdit_localhost->setText(address.toString());
		}
	}
	ui.comboBox->setEditable(true);

	//启动服务器监听
	HttpServer::GetInst().setIP(ui.lineEdit_localhost->text());
	HttpServer::GetInst().setPort(PORT);
	if (HttpServer::GetInst().start())
	{
		connect(HttpServer::GetInst().request, &RequestHandler::sendPoint, this, &fiveGo::on_getPoint);
		connect(HttpServer::GetInst().request, &RequestHandler::getStart, this, &fiveGo::on_getStrat);
		connect(HttpServer::GetInst().request, &RequestHandler::getStartRes, this, &fiveGo::on_getStratRes);
		connect(HttpServer::GetInst().request, &RequestHandler::getMsg, this, &fiveGo::on_getMsg);
	}

	label = QPixmap(SIZE, SIZE);
	auto color = this->palette().color(QPalette::Window);
	label.fill(qRgb(82,82,82)); //图片背景色和窗口背景一致
	background = new BackgroundItem(color);
	scene = new QGraphicsScene();
	scene->addItem(background);
	ui.graphicsView->setScene(scene);
	ui.graphicsView->setEnabled(false);

	connect(ui.btn_history, &QPushButton::clicked, this, &fiveGo::on_load);
	//加载历史对局
	connect(this, &fiveGo::loadMunual, background, &BackgroundItem::on_loadMunual);
	//给棋盘发送赢信号
	connect(this, &fiveGo::isWiner, background, &BackgroundItem::on_isWiner);
	//给棋盘发送落子信号
	connect(this, &fiveGo::drawPoint, background, &BackgroundItem::on_drawPoint);
	//给棋盘发送单机开始信号
	connect(this, &fiveGo::startOne, background, &BackgroundItem::on_startOne);
	connect(this, &fiveGo::startTwo, background, &BackgroundItem::on_startOne);
	//发送消息
	connect(ui.btn_send, &QPushButton::clicked, this, &fiveGo::on_send);
	//单机开始
	connect(ui.btn_start, &QPushButton::clicked, this, &fiveGo::on_start);
	//认输or重新开始
	connect(ui.btn_defult, &QPushButton::clicked, this, &fiveGo::on_defult);
	//棋盘落子后返回信号检查胜负
	connect(background, &BackgroundItem::nowFlag, this, &fiveGo::on_nowflag);
	//开始局域网对局
	connect(ui.btn_connect, &QPushButton::clicked, [=]() {
		if (ui.lineEdit_2->text().isEmpty() || ui.lineEdit_2->text() == ui.lineEdit_localhost->text())
			return;
		url = "http://" + ui.lineEdit_2->text() + ":" + QString::number(PORT) + "/fiveGo/";
		//http发送落子信息
		QJsonObject obj;
		obj.insert("res", true);
		if (!http.postUrl(url + "start", obj, QByteArray()))
		{
			auto res = QMessageBox::information(this, u8"消息", u8"连接超时，请检查IP", QMessageBox::Ok);
		}	
	});
}

bool fiveGo::check(MyPoint p, MyChess f)
{
	//左上到右下检查
	int i = 1;
	int num = 1;
	auto new_p = MyPoint(p.x() - i * S, p.y() - i * S);
	while (map.find(new_p) != map.end() && map.find(new_p).value() == f)
	{
		i++;
		num++;
		if (num == 5)
			return true;
		else
		{
			new_p = MyPoint(p.x() - i * S, p.y() - i * S);
		}
	}
	i = 1;
	new_p = MyPoint(p.x() + i * S, p.y() + i * S);
	while (map.find(new_p) != map.end() && map.find(new_p).value() == f)
	{
		i++;
		num++;
		if (num == 5)
			return true;
		else
		{
			new_p = MyPoint(p.x() + i * S, p.y() + i * S);
		}
	}

	//上到下检查
	i = 1; num = 1;
	new_p = MyPoint(p.x(), p.y() - i * S);
	while (map.find(new_p) != map.end() && map.find(new_p).value() == f)
	{
		i++;
		num++;
		if (num == 5)
			return true;
		else
		{
			new_p = MyPoint(p.x(), p.y() - i * S);
		}
	}
	i = 1;
	new_p = MyPoint(p.x(), p.y() + i * S);
	while (map.find(new_p) != map.end() && map.find(new_p).value() == f)
	{
		i++;
		num++;
		if (num == 5)
			return true;
		else
		{
			new_p = MyPoint(p.x(), p.y() + i * S);
		}
	}

	//右上到左下检查
	i = 1; num = 1;
	new_p = MyPoint(p.x() + i * S, p.y() - i * S);
	while (map.find(new_p) != map.end() && map.find(new_p).value() == f)
	{
		i++;
		num++;
		if (num == 5)
			return true;
		else
		{
			new_p = MyPoint(p.x() + i * S, p.y() - i * S);
		}
	}
	i = 1;
	new_p = MyPoint(p.x() - i * S, p.y() + i * S);
	while (map.find(new_p) != map.end() && map.find(new_p).value() == f)
	{
		i++;
		num++;
		if (num == 5)
			return true;
		else
		{
			new_p = MyPoint(p.x() - i * S, p.y() + i * S);
		}
	}

	//左到右检查
	i = 1; num = 1;
	new_p = MyPoint(p.x() + i * S, p.y());
	while (map.find(new_p) != map.end() && map.find(new_p).value() == f)
	{
		i++;
		num++;
		if (num == 5)
			return true;
		else
		{
			new_p = MyPoint(p.x() + i * S, p.y());
		}
	}
	i = 1;
	new_p = MyPoint(p.x() - i * S, p.y());
	while (map.find(new_p) != map.end() && map.find(new_p).value() == f)
	{
		i++;
		num++;
		if (num == 5)
			return true;
		else
		{
			new_p = MyPoint(p.x() - i * S, p.y());
		}
	}
	return false;
}

void fiveGo::refresh()
{
	QPainter p(&label);
	p.setBrush(nowChess == MyChess::black ? Qt::black : Qt::white);
	p.drawEllipse(0, 0, SIZE, SIZE);
	ui.label_4->setPixmap(label);
	if (isStandAlone)
	{
		ui.label_7->setPixmap(label);
	}
}

void fiveGo::save()
{
	QJsonObject obj;
	int i = 0;
	for (auto &value : munual)
	{
		QJsonObject ob;
		ob.insert("x", value.first.x());
		ob.insert("y", value.first.y());
		ob.insert("chess", value.second);
		obj.insert(QString::number(i), ob);
		i++;
	}
	QDateTime dateTime = QDateTime::currentDateTime();//获取系统当前的时间
	QString str = QCoreApplication::applicationDirPath() +  "/history/" + dateTime.toString("yyyy-MM-dd_hh_mm_ss") + ".his";//存储路径
	QJsonDocument doc(obj);
	QByteArray result = doc.toJson().toBase64();  //Base64加密
	QFile f(str);
	if (f.open(QIODevice::WriteOnly))
	{
		f.write(result);
		f.close();
	}
}

void fiveGo::on_start()
{
	ui.graphicsView->setEnabled(true);
	isStandAlone = true;	//单机模式
	ui.btn_start->setEnabled(false);
	map.clear();
	munual.clear();
	this->nowChess = MyChess::black;
	this->yourChess = nowChess;
	refresh();
	ui.btn_history->setEnabled(false);
	emit startOne();
}

void fiveGo::on_defult()
{
	if (isStandAlone)
	{
		auto res = QMessageBox::Ok;
		if (!background->flished)
		{
			res = QMessageBox::information(this, u8"认输", u8"是否认输且重新开始", QMessageBox::Ok | QMessageBox::No);
		}
		if (res == QMessageBox::Ok)
		{
			ui.btn_history->setEnabled(false);
			map.clear();
			munual.clear();
			if (isStandAlone)
			{
				nowChess = MyChess::black;
				yourChess = nowChess;
				emit startOne();
			}
			refresh();
		}
	}
	else
	{
		auto res = QMessageBox::information(this, u8"坚持", u8"对局不易，坚持就是胜利，奥里给！！！", QMessageBox::Ok);
	}
	
}

void fiveGo::on_nowflag(MyPoint point)
{
	if (nowChess != yourChess)
		return;
	//胜负判定
	if (map.find(point) == map.end())
	{
		map.insert(point, nowChess);
		munual.append(std::pair<MyPoint, MyChess>(point, nowChess));
		auto it = map.find(point);
		auto res = check(point, nowChess);
		emit drawPoint(point, nowChess);
		//http发送落子信息
		QJsonObject obj;
		obj.insert("x", point.x());
		obj.insert("y", point.y());
		http.postUrl(url + "chess", obj, QByteArray());
		if (res)
		{
			emit isWiner(nowChess, munual);
			save();
			ui.btn_history->setEnabled(true);
			ui.btn_start->setEnabled(true);
			ui.btn_connect->setEnabled(true);
		}
		nowChess = (nowChess == MyChess::black) ? MyChess::white : MyChess::black;
		if (isStandAlone)
			yourChess = nowChess;
		//刷新界面
		refresh();
	}
}

void fiveGo::on_load()
{
	auto str = QCoreApplication::applicationDirPath() + "/history/";
	QString fileName = QFileDialog::getOpenFileName(this,tr("open a file."),str,tr("files(*.his);"));

	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "open error" << file.fileName();
		return ;
	}
	QJsonParseError jerr;
	//Base64解密
	auto res = QByteArray::fromBase64(file.readAll());
	QJsonDocument doc = QJsonDocument::fromJson(res, &jerr);
	if (doc.isNull())
	{
		qDebug() << jerr.errorString();
		return ;
	}
	QJsonObject jroot = doc.object();
	auto keys = jroot.keys().size();
	QList<std::pair<MyPoint, MyChess>> list;
	for (int index = 0; index < keys; index++)
	{
		auto i = QString::number(index);
		auto obj = jroot[i].toObject();
		MyPoint p(obj["x"].toInt(), obj["y"].toInt());
		MyChess c = MyChess(obj["chess"].toInt());
		list.append(std::pair<MyPoint, MyChess>(p, c));
	}
	emit loadMunual(list);
	ui.label_4->clear();
	ui.label_7->clear();
}

void fiveGo::on_getPoint(MyPoint point)
{
	//当前棋子不为自己时接收落子点位
	if (nowChess != yourChess)
	{
		//胜负判定
		if (map.find(point) == map.end())
		{
			map.insert(point, nowChess);
			munual.append(std::pair<MyPoint, MyChess>(point, nowChess));
			auto it = map.find(point);
			auto res = check(point, nowChess);
			emit drawPoint(point, nowChess);
			if (res)
			{
				emit isWiner(nowChess, munual);
				save();
				ui.btn_history->setEnabled(true);
				ui.btn_start->setEnabled(true);
				ui.btn_connect->setEnabled(true);
			}
			else
			{
				//回合轮转
				nowChess = yourChess;
			}
			//刷新界面
			refresh();
		}
	}
}

void fiveGo::on_getStrat(QString ip)
{
	QString msg = u8"收到对局邀请是否开始对局\n对方IP:" + ip;
	auto res = QMessageBox::information(NULL, u8"对局邀请", msg, QMessageBox::Ok | QMessageBox::No);
	QJsonObject obj;
	if (res == QMessageBox::Ok)
	{
		isStandAlone = false;
		isClient = true;	//发起端为客户端,执黑先行,后续交替
		this->nowChess = MyChess::black;
		this->yourChess = MyChess::white;//接收方为白字
		refresh();
		QPainter p(&label);
		p.setBrush(yourChess == MyChess::black ? Qt::black : Qt::white);
		p.drawEllipse(0, 0, SIZE, SIZE);
		ui.label_7->setPixmap(label);
		history.clear();
		map.clear();
		munual.clear();
		ui.btn_history->setEnabled(false);
		ui.graphicsView->setEnabled(true);
		ui.btn_start->setEnabled(false);
		ui.btn_connect->setEnabled(false);
		obj.insert("res", true);
		ui.lineEdit_2->setText(ip);
		url = "http://" + ui.lineEdit_2->text() + ":" + QString::number(PORT) + "/fiveGo/";
		http.postUrl(url + "startRes", obj, QByteArray());
		emit startTwo();
	}
	else
	{
		obj.insert("res", false);
		auto url1 = "http://" +ip + ":" + QString::number(PORT) + "/fiveGo/";
		http.postUrl(url1 + "startRes", obj, QByteArray());
	}
	
}

void fiveGo::on_getStratRes(bool res)
{
	if (res)
	{
		isStandAlone = false;
		isClient = true;	//发起端为客户端,执黑先行,后续交替
		this->nowChess = MyChess::black;
		this->yourChess = nowChess;
		refresh();
		QPainter p(&label);
		p.setBrush(yourChess == MyChess::black ? Qt::black : Qt::white);
		ui.label_7->setPixmap(label);
		history.clear();
		map.clear();
		munual.clear();
		ui.btn_history->setEnabled(false);
		ui.btn_start->setEnabled(false);
		ui.btn_connect->setEnabled(false);
		ui.graphicsView->setEnabled(true);
		emit startTwo();
	}
	else
	{
		QMessageBox::information(NULL, u8"消息", u8"对方拒绝了请求", QMessageBox::Ok);
	}
}

void fiveGo::on_getMsg(QString msg)
{
	ui.textEdit->setTextColor(Qt::green);
	QString data = ui.lineEdit_2->text() + ":" + msg;
	ui.textEdit->append(data);
	ui.textEdit->moveCursor(QTextCursor::End);
}

void fiveGo::on_send()
{
	QString msg = ui.comboBox->currentText();
	ui.textEdit->setTextColor(Qt::green);
	QString data = ui.lineEdit_localhost->text() + ":" + msg;
	ui.textEdit->append(data);
	ui.textEdit->moveCursor(QTextCursor::End);
	//http发送落子信息
	QJsonObject obj;
	obj.insert("msg", msg);
	if (!http.postUrl(url + "msg", obj, QByteArray()))
	{
		ui.textEdit->setTextColor(Qt::red);
		QString err = u8"发送数据超时，请检查连接状态";
		ui.textEdit->append(err);
		ui.textEdit->moveCursor(QTextCursor::End);
	}
}
