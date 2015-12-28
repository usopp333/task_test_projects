//////////////////////////////////////////////////////////////////
//
// Qt 的绘图系统
// 
// Qt 的绘图系统实际上是，使用QPainter在QPainterDevice上进行绘制，
// 它们之间使用QPaintEngine进行通讯（也就是翻译QPainter的指令）。
// 
//////////////////////////////////////////////////////////////////

#include "qt_qpainter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//PainteWidget w;
	ColorWheel w; //绘制一个色轮
	w.show();
	return a.exec();
}
