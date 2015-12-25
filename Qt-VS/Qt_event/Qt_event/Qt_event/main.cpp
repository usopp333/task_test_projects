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
	label->setMouseTracking(true);	//�Ƿ�׷����꣨Ĭ����false��׷�٣�
	label->show();

	return a.exec();
}