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
	//ͨ��������ȡ������ip
	QHostInfo info = QHostInfo::fromName(QHostInfo::localHostName());
	foreach(QHostAddress address, info.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol)
		{
			//�������IPV4�ĵ�ַ �����ַ��ʾ���һ��
			ui.lineEdit_localhost->setText(address.toString());
		}
	}
	ui.comboBox->setEditable(true);

	//��������������
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
	label.fill(qRgb(82,82,82)); //ͼƬ����ɫ�ʹ��ڱ���һ��
	background = new BackgroundItem(color);
	scene = new QGraphicsScene();
	scene->addItem(background);
	ui.graphicsView->setScene(scene);
	ui.graphicsView->setEnabled(false);

	connect(ui.btn_history, &QPushButton::clicked, this, &fiveGo::on_load);
	//������ʷ�Ծ�
	connect(this, &fiveGo::loadMunual, background, &BackgroundItem::on_loadMunual);
	//�����̷���Ӯ�ź�
	connect(this, &fiveGo::isWiner, background, &BackgroundItem::on_isWiner);
	//�����̷��������ź�
	connect(this, &fiveGo::drawPoint, background, &BackgroundItem::on_drawPoint);
	//�����̷��͵�����ʼ�ź�
	connect(this, &fiveGo::startOne, background, &BackgroundItem::on_startOne);
	connect(this, &fiveGo::startTwo, background, &BackgroundItem::on_startOne);
	//������Ϣ
	connect(ui.btn_send, &QPushButton::clicked, this, &fiveGo::on_send);
	//������ʼ
	connect(ui.btn_start, &QPushButton::clicked, this, &fiveGo::on_start);
	//����or���¿�ʼ
	connect(ui.btn_defult, &QPushButton::clicked, this, &fiveGo::on_defult);
	//�������Ӻ󷵻��źż��ʤ��
	connect(background, &BackgroundItem::nowFlag, this, &fiveGo::on_nowflag);
	//��ʼ�������Ծ�
	connect(ui.btn_connect, &QPushButton::clicked, [=]() {
		if (ui.lineEdit_2->text().isEmpty() || ui.lineEdit_2->text() == ui.lineEdit_localhost->text())
			return;
		url = "http://" + ui.lineEdit_2->text() + ":" + QString::number(PORT) + "/fiveGo/";
		//http����������Ϣ
		QJsonObject obj;
		obj.insert("res", true);
		if (!http.postUrl(url + "start", obj, QByteArray()))
		{
			auto res = QMessageBox::information(this, u8"��Ϣ", u8"���ӳ�ʱ������IP", QMessageBox::Ok);
		}	
	});
}

bool fiveGo::check(MyPoint p, MyChess f)
{
	//���ϵ����¼��
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

	//�ϵ��¼��
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

	//���ϵ����¼��
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

	//���Ҽ��
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
	QDateTime dateTime = QDateTime::currentDateTime();//��ȡϵͳ��ǰ��ʱ��
	QString str = QCoreApplication::applicationDirPath() +  "/history/" + dateTime.toString("yyyy-MM-dd_hh_mm_ss") + ".his";//�洢·��
	QJsonDocument doc(obj);
	QByteArray result = doc.toJson().toBase64();  //Base64����
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
	isStandAlone = true;	//����ģʽ
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
			res = QMessageBox::information(this, u8"����", u8"�Ƿ����������¿�ʼ", QMessageBox::Ok | QMessageBox::No);
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
		auto res = QMessageBox::information(this, u8"���", u8"�Ծֲ��ף���־���ʤ���������������", QMessageBox::Ok);
	}
	
}

void fiveGo::on_nowflag(MyPoint point)
{
	if (nowChess != yourChess)
		return;
	//ʤ���ж�
	if (map.find(point) == map.end())
	{
		map.insert(point, nowChess);
		munual.append(std::pair<MyPoint, MyChess>(point, nowChess));
		auto it = map.find(point);
		auto res = check(point, nowChess);
		emit drawPoint(point, nowChess);
		//http����������Ϣ
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
		//ˢ�½���
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
	//Base64����
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
	//��ǰ���Ӳ�Ϊ�Լ�ʱ�������ӵ�λ
	if (nowChess != yourChess)
	{
		//ʤ���ж�
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
				//�غ���ת
				nowChess = yourChess;
			}
			//ˢ�½���
			refresh();
		}
	}
}

void fiveGo::on_getStrat(QString ip)
{
	QString msg = u8"�յ��Ծ������Ƿ�ʼ�Ծ�\n�Է�IP:" + ip;
	auto res = QMessageBox::information(NULL, u8"�Ծ�����", msg, QMessageBox::Ok | QMessageBox::No);
	QJsonObject obj;
	if (res == QMessageBox::Ok)
	{
		isStandAlone = false;
		isClient = true;	//�����Ϊ�ͻ���,ִ������,��������
		this->nowChess = MyChess::black;
		this->yourChess = MyChess::white;//���շ�Ϊ����
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
		isClient = true;	//�����Ϊ�ͻ���,ִ������,��������
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
		QMessageBox::information(NULL, u8"��Ϣ", u8"�Է��ܾ�������", QMessageBox::Ok);
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
	//http����������Ϣ
	QJsonObject obj;
	obj.insert("msg", msg);
	if (!http.postUrl(url + "msg", obj, QByteArray()))
	{
		ui.textEdit->setTextColor(Qt::red);
		QString err = u8"�������ݳ�ʱ����������״̬";
		ui.textEdit->append(err);
		ui.textEdit->moveCursor(QTextCursor::End);
	}
}
