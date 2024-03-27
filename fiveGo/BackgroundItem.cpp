#include "BackgroundItem.h"
#include <QPainter>


BackgroundItem::BackgroundItem()
{
	init();
}


BackgroundItem::~BackgroundItem()
{

}


void BackgroundItem::init()
{
	QPixmap map(480, 480);
	map.fill(color);
	QPainter painter(&map);
	painter.setPen(QPen(Qt::black));

	for (int i = 1; i < 16; i++)
	{
		painter.drawLine(i * S, S,i * S, 15* S);
	}
	for (int i = 1; i < 16; i++)
	{
		painter.drawLine( S, i * S, 15 * S, i * S);
	}
	//绘制棋盘标号1-15
	for (int i = 0; i < 15; i++)
	{
		painter.drawText(QRect(5, (i + 1) * S - 5,10,10), Qt::AlignHCenter, QString::number(i + 1));
	}
	//绘制棋盘标号A-O
	for (int i = 0; i < 15; i++)
	{
		painter.drawText(QRect((i + 1) * S - 5,5 , 10, 10), Qt::AlignHCenter, QString(char('A' + i)));
	}

	//绘制5个小圆
	painter.setBrush(QBrush(Qt::black));
	painter.drawEllipse(S * 4 - 8, S * 4 - 8, 16, 16);
	painter.drawEllipse(S * 12 - 8, S * 12 - 8, 16, 16);
	painter.drawEllipse(S * 12 - 8, S * 4 - 8, 16, 16);
	painter.drawEllipse(S * 4 - 8, S * 12 - 8, 16, 16);
	painter.drawEllipse(S * 8 - 8, S * 8 - 8, 16, 16);
	back = map.copy();
	backUsed = back.copy();
	this->setPixmap(backUsed);
}


void BackgroundItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	if (flished)
		return;
	//控制落子全部都在棋盘交点处
	auto pos = event->pos();
	auto new_x = round(pos.x() / S) * S;
	auto new_y = round(pos.y() / S) * S;
	
	new_x = new_x > 450 ? 450 : new_x;
	new_y = new_y > 450 ? 450 : new_y;
	new_x = new_x < S ? S : new_x;
	new_y = new_y < S ? S : new_y;

	emit nowFlag(MyPoint(new_x, new_y));
}

void BackgroundItem::on_isWiner(MyChess d, QList<std::pair<MyPoint, MyChess>> m)
{
	flished = true;
	QPainter painter(&backUsed);
	painter.setPen(Qt::blue);
	painter.setFont(QFont("Consolas", 50, 10));
	QString text = d == MyChess::black ? u8"黑棋胜" : u8"白棋胜";
	painter.drawText(backUsed.rect(), Qt::AlignCenter, text);

	//复盘
	painter.setPen(Qt::green);
	painter.setFont(QFont("Consolas", 10, 1));
	for (int i = 0; i < m.size(); i++)
	{
		//painter.drawText(m[i].first.x()-3, m[i].first.y()+5, QString::number(i+1));
		painter.drawText(QRect(m[i].first.x() - 14, m[i].first.y() - 14,28,28), Qt::AlignCenter, QString::number(i + 1));
	}
	this->setPixmap(backUsed);
}

void BackgroundItem::on_drawPoint(MyPoint p, MyChess d)
{
	QPainter painter(&backUsed);
	if (d == MyChess::black)
	{
		painter.setBrush(QBrush(Qt::black));
	}
	else if (d == MyChess::white)
	{
		painter.setBrush(QBrush(Qt::white));
	}
	painter.drawEllipse(p.x() - 14, p.y() - 14, 28, 28);
	this->setPixmap(backUsed);
}

void BackgroundItem::on_startOne()
{
	flished = false;
	backUsed = back.copy();
	this->setPixmap(backUsed);
}

void BackgroundItem::on_loadMunual(QList<std::pair<MyPoint, MyChess>> m)
{
	//复盘
	backUsed = back.copy();
	QPainter painter(&backUsed);
	painter.setPen(Qt::green);
	for (int i = 0; i < m.size(); i++)
	{
		if (m[i].second == MyChess::black)
		{
			painter.setBrush(QBrush(Qt::black));
		}
		else if (m[i].second == MyChess::white)
		{
			painter.setBrush(QBrush(Qt::white));
		}
		painter.drawEllipse(m[i].first.x() - 14, m[i].first.y() - 14, 28, 28);
		painter.setPen(Qt::green);
		painter.setFont(QFont("Consolas", 10, 1));
		painter.drawText(QRect(m[i].first.x() - 14, m[i].first.y() - 14, 28, 28), Qt::AlignCenter, QString::number(i + 1));
	}
	this->setPixmap(backUsed);
}
