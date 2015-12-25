#ifndef QT_EVENT_H
#define QT_EVENT_H

#include <QtWidgets/QMainWindow>
#include "ui_qt_event.h"
#include <QLabel>
#include <QMouseEvent>
#include <QString>

class EventLabel : public QLabel
{
protected:
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};


#endif // QT_EVENT_H
