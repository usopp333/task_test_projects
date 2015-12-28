#ifndef QT_QPAINTER_H
#define QT_QPAINTER_H

#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QPaintDevice>
#include <QPaintEngine>
//#include <QtCore/qbrush.h>

#include "ui_qt_qpainter.h"



class PainteWidget : public QWidget
{
	Q_OBJECT
public:
	PainteWidget(QWidget *parent = 0);
protected:
	void paintEvent(QPaintEvent *);
};

class ColorWheel : public QWidget
{
	Q_OBJECT
public:
	ColorWheel(QWidget *parent = 0);
protected:
	void paintEvent(QPaintEvent *);
};
#endif // QT_QPAINTER_H
