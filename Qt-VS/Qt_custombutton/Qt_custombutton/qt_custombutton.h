#ifndef QT_CUSTOMBUTTON_H
#define QT_CUSTOMBUTTON_H

#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>
#include "ui_qt_custombutton.h"

class CustomButton:public QPushButton
{
	Q_OBJECT
public:
	CustomButton(QWidget *parnet = 0);
private:
	void onButtonCilecked();
protected:
	void mousePressEvent(QMouseEvent *event);
};
#endif // QT_CUSTOMBUTTON_H
