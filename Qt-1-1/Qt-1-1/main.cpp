// 对于Qt的学习
#include "stdafx.h"
#include "myclass.h"
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>

// //1.1 hello qt
// int main(int argc, char *argv[])
// {
// 	QApplication a(argc, argv);
// 	QLabel *label = new QLabel("<h2><i>Hello</i> "
// 		"<font color=red>Qt!</font></h2>");
// 	label->show();
// 	return a.exec();
// }

//1.2 a quit button
// int main(int argc, char *argv[])
// {
// 	QApplication app(argc,argv);
// 	QPushButton *button = new QPushButton("Quit");
// 	QObject::connect(button,SIGNAL(clicked()),
// 					 &app,SLOT(quit()));
// 	button->show();
// 	return app.exec();
// }


//1.3 lyout
int main(int argc,char *argv[])
{
	QApplication app(argc,argv);
	
	QWidget *window = new QWidget;
	window->setWindowTitle("Enter Your Age");
	
	QSpinBox *spinBox = new QSpinBox;
	QSlider*slider = new QSlider(Qt::Horizontal);
	spinBox->setRange(0,130);
	slider->setRange(0,130);

	QObject::connect(spinBox,SIGNAL(valueChanged(int)),
		             slider,SLOT(setValue(int)));
	QObject::connect(slider,SIGNAL(valueChanged(int)),
		             spinBox,SLOT(setValue(int)));
	spinBox->setValue(35);
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(spinBox);
	layout->addWidget(slider);
	window->setLayout(layout);

	window->show();

	return app.exec();
}


