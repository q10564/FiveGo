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
	bool isStandAlone = false;	//是否单机
	bool isClient = false;	//是否为客户端(发起端为客户端)
	MyChess nowChess = MyChess::black;
	MyChess yourChess = MyChess::black;
	std::vector<QString> history;	//对局记录胜方IP
	QMap<MyPoint, MyChess> map;	//记录落子坐标方便判定胜负
	QList<std::pair<MyPoint, MyChess>> munual;		//棋谱记录落子顺序


	bool check(MyPoint p, MyChess f);
	void refresh();
	void save();	//保存对局
	
public slots:
	void on_load();	//加载对局
	void on_start();//单机开始
	void on_defult();//认输或重新开始
	void on_nowflag(MyPoint point);
	void on_getPoint(MyPoint point);
	void on_getStrat(QString ip);	//收到对局邀请
	void on_getStratRes(bool);	//发送邀请结果
	void on_getMsg(QString msg);
	void on_send();
signals:
	void isWiner(MyChess, QList<std::pair<MyPoint, MyChess>>);
	void drawPoint(MyPoint, MyChess);
	void startOne();
	void startTwo();
	void loadMunual(QList<std::pair<MyPoint, MyChess>>);
};
