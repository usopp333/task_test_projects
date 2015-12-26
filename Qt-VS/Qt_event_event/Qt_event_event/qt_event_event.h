#ifndef QT_EVENT_EVENT_H
#define QT_EVENT_EVENT_H

#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include "ui_qt_event_event.h"


class CustomWidget : public QWidget
{
	Q_OBJECT

protected:
	bool CustomWidget::event(QEvent *e);
// 	{
// 		if (e->type() == QEvent::KeyPress) {
// 			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
// 			if (keyEvent->key() == Qt::Key_Tab) {
// 				qDebug() << "You press tab.";
// 				return true;
// 			}
// 		}
// 		return QWidget::event(e);
// 	}
};
#endif // QT_EVENT_EVENT_H
