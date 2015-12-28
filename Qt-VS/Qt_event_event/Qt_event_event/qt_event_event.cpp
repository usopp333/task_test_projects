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

// �¼�����������EventFilter
//��װ������
// void QObject::installEventFilter ( QObject * filterObj )
// �Ѿ����ڵĹ����������ͨ��QObject::removeEventFilter()�����Ƴ�
MainWindow :: MainWindow()
{
	textEdit = new QTextEdit;
	setCentralWidget(textEdit);

	textEdit->installEventFilter(this);
}
//��������¼��������� delete ��ĳ�������������ؽ���������ֵ��Ϊ true��
// ����Qt ���ǻὫ�¼��ַ����������������Ӷ����³������
// �¼��������ͱ���װ�����������������ͬһ�̣߳����򣬹��������������á�
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
