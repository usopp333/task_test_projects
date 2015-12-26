#include "qt_event_event.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CustomWidget w;
	w.show();
	return a.exec();
}
