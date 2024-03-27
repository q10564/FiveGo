#pragma once

#include <QtWidgets/QWidget>
#include "ui_fiveGo.h"
#include <QString>
#include <QGraphicsScene>
#include "BackgroundItem.h"
#include "HttpEngine.h"

#define PORT (8848)
#define SIZE (50)
class fiveGo : public QWidget
{
	Q_OBJECT

public:
	fiveGo(QWidget *parent = Q_NULLPTR);

private:
	Ui::fiveGoClass ui;
	QString connect_ip;
	QGraphicsScene *scene;
	HttpEngine http;
	QString url;
	BackgroundItem *background;
	QPixmap label;
	bool isStandAlone = false;	//�Ƿ񵥻�
	bool isClient = false;	//�Ƿ�Ϊ�ͻ���(�����Ϊ�ͻ���)
	MyChess nowChess = MyChess::black;
	MyChess yourChess = MyChess::black;
	std::vector<QString> history;	//�Ծּ�¼ʤ��IP
	QMap<MyPoint, MyChess> map;	//��¼�������귽���ж�ʤ��
	QList<std::pair<MyPoint, MyChess>> munual;		//���׼�¼����˳��


	bool check(MyPoint p, MyChess f);
	void refresh();
	void save();	//����Ծ�
	
public slots:
	void on_load();	//���ضԾ�
	void on_start();//������ʼ
	void on_defult();//��������¿�ʼ
	void on_nowflag(MyPoint point);
	void on_getPoint(MyPoint point);
	void on_getStrat(QString ip);	//�յ��Ծ�����
	void on_getStratRes(bool);	//����������
	void on_getMsg(QString msg);
	void on_send();
signals:
	void isWiner(MyChess, QList<std::pair<MyPoint, MyChess>>);
	void drawPoint(MyPoint, MyChess);
	void startOne();
	void startTwo();
	void loadMunual(QList<std::pair<MyPoint, MyChess>>);
};
