#include "qt_event.h"

void EventLabel::mouseMoveEvent(QMouseEvent *event)
{
	//QString("[%1, %2]").arg(x,y);
	//��佫��ʹ��x�滻%1��y�滻%2����ˣ����������ɵ�QStringΪ[x,y];
	// QString��arg()���������Զ��滻��QString�г��ֵ�ռλ��
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
	//��һ��ʵ����ʽ����ʽ���������sprintf������QString��
	QString msg;
	msg.sprintf("<center><h1>Release: (%d, %d)</h1></center>",
		event->x(), event->y());
	this->setText(msg);

// 	this->setText(QString("<center><h1>Release: (%1, %2)</h1></center>")
// 		.arg(QString::number(event->x()), QString::number(event->y())));
}