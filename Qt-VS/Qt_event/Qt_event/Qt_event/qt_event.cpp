#include "qt_event.h"

void EventLabel::mouseMoveEvent(QMouseEvent *event)
{
	//QString("[%1, %2]").arg(x,y);
	//语句将会使用x替换%1，y替换%2，因此，这个语句生成的QString为[x,y];
	// QString的arg()函数可以自动替换掉QString中出现的占位符
	this->setText(QString("<center><h1>Move: (%1, %2)</h1></center>")
		.arg(QString::number(event->x()), QString::number(event->y())));
}

void EventLabel::mousePressEvent(QMouseEvent *event)
{
	this->setText(QString("<center><h1>Press: (%1, %2)</h1></center>")
		.arg(QString::number(event->x()), QString::number(event->y())));
}

void EventLabel::mouseReleaseEvent(QMouseEvent *event)
{
	//另一种实现形式，格式化输出函数sprintf来构造QString；
	QString msg;
	msg.sprintf("<center><h1>Release: (%d, %d)</h1></center>",
		event->x(), event->y());
	this->setText(msg);

// 	this->setText(QString("<center><h1>Release: (%1, %2)</h1></center>")
// 		.arg(QString::number(event->x()), QString::number(event->y())));
}