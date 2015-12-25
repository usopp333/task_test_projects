#include "qt_event.h"
#include <QtWidgets/QApplication>

// int main(int argc, char *argv[])
// {
// 	QApplication a(argc, argv);
// 	Qt_event w;
// 	w.show();
// 	return a.exec();
// }

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	EventLabel *label = new EventLabel;
	label->setWindowTitle("MouseEvent Demo");
	label->resize(300, 200);
	label->setMouseTracking(true);	//是否追踪鼠标（默认是false不追踪）
	label->show();

	return a.exec();
}