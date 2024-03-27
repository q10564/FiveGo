#pragma once
#include <qgraphicsitem.h>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QPoint>
#include <QMap>
#include <QObject>
#define S (30)	//棋盘格大小
struct Mymunual;
enum MyChess
{
	black = 0,
	white = 1,
};

class MyPoint :public QPoint
{
public:
	MyPoint() {setX(0); setY(0); }
	MyPoint(int x, int y) { this->setX(x); setY(y); }
	bool operator<(const MyPoint& rhs) const  //重载<运算符，map中需要用到
	{
		if (this->x() < rhs.x())
			return true;
		else if (this->x() > rhs.x())
			return false;
		else if (this->y() < rhs.y())
			return true;
		else if (this->x() > rhs.x())
			return false;
		return false;
	}
};
class BackgroundItem : public QObject,public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	BackgroundItem();
	BackgroundItem(QColor c) :color(c) { init(); };
	~BackgroundItem();
	bool flished = false;
private:
	void init();
	QPixmap back;	//初始棋盘
	QPixmap backUsed;	//当前绘制的棋盘
	QColor color;
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
	void nowFlag(MyPoint);
public slots:
	void on_isWiner(MyChess d, QList<std::pair<MyPoint, MyChess>> m);
	void on_drawPoint(MyPoint p, MyChess d);
	void on_startOne();
	void on_loadMunual(QList<std::pair<MyPoint, MyChess>>);
};

