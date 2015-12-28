#include "qt_event_event.h"


bool CustomWidget::event(QEvent *e)
{
	if (e->type() == QEvent::KeyPress) {
		QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
		if (keyEvent->key() == Qt::Key_Tab) {
			qDebug() << "You press tab.";
			return true;
		}
	}
	return QWidget::event(e);
}

// 事件过滤器测试EventFilter
//安装过滤器
// void QObject::installEventFilter ( QObject * filterObj )
// 已经存在的过滤器则可以通过QObject::removeEventFilter()函数移除
MainWindow :: MainWindow()
{
	textEdit = new QTextEdit;
	setCentralWidget(textEdit);

	textEdit->installEventFilter(this);
}
//如果你在事件过滤器中 delete 了某个接收组件，务必将函数返回值设为 true。
// 否则，Qt 还是会将事件分发给这个接收组件，从而导致程序崩溃
// 事件过滤器和被安装过滤器的组件必须在同一线程，否则，过滤器将不起作用。
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
	if(obj == textEdit){
		if(event->type() == QEvent::KeyPress){
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			qDebug()<<"Ate key press"<<keyEvent->key();
			return true;
		} else {
			return false;
		}
	} else {
		// pass the event on to the parent class
		return QMainWindow::eventFilter(obj,event);
	}
}
