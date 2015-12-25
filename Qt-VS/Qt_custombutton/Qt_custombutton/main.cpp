#include "qt_custombutton.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CustomButton w;
	w.setText("This is a Button!");
	w.show();
	return a.exec();
}
