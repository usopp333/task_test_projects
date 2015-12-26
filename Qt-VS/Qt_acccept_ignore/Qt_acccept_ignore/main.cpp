/////////////////////////////////////////////
//
//  针对accept()和ignore()的例子
//
///////////////////////////////////////////// 
#include "qt_acccept_ignore.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
