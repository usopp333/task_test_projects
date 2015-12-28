#ifndef QT_EVENT_EVENT_H
#define QT_EVENT_EVENT_H

#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QTextEdit>

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

// �¼�����������EventFilter
//�����¼�������
//virtual bool QObject::eventFilter ( QObject * watched, QEvent * event );
// 
class  MainWindow:public QMainWindow
{
public:
	MainWindow();
protected:
	bool eventFilter(QObject *obj, QEvent *event);
private:
	QTextEdit *textEdit;
};

// �����¼�����ʽ�ĵ���˳��
// ȫ���¼�����������һ�����ã�֮���Ǹö���������¼��������������event()������������ض����¼���������
class  Label:public QWidget
{
public:
	Label()
	{
		installEventFilter(this);
	}
	bool eventFilter(QObject *watched, QEvent *event)
	{
		if(watched == this){
			if(event->type() == QEvent::MouseButtonPress){
				qDebug()<<"eventFilter";
			}
		}
		return false;
	}
protected:
	void mousePressEvent(QMouseEvent *)
	{
		qDebug()<<"mousePressEvent";
	}
	bool event(QEvent *e)
	{
		if(e->type() == QEvent::MouseButtonPress){
			qDebug()<<"event";
		}
		return QWidget::event(e);
	}
};
class EventFilter:public QObject
{
public:
	EventFilter(QObject *watched, QObject *parent = 0):
	QObject(parent),
		m_watched(watched)
	{
	}
	bool eventFilter(QObject *watched, QEvent *event)
	{
		if(watched == m_watched){
			if(event->type() == QEvent::MouseButtonPress){
				qDebug()<<"QApplication::eventFilter";
			}
		}
		return false;
	}
private:
	QObject *m_watched;
};
#endif // QT_EVENT_EVENT_H
