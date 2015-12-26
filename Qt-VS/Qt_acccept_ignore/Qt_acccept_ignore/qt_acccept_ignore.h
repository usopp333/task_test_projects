#ifndef QT_ACCCEPT_IGNORE_H
#define QT_ACCCEPT_IGNORE_H

#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>
#include <QVBoxLayout>


class CustomButton : public QPushButton
{
	Q_OBJECT

public:
	CustomButton::CustomButton(QWidget *parent)
		:QPushButton(parent)
	{
	}
protected:
	void mousePressEvent(QMouseEvent *event)
	{
		qDebug()<<"CustomButton";
	}
};

class CustomButtonEx : public CustomButton
{
	Q_OBJECT
public:
	CustomButtonEx::CustomButtonEx(QWidget *parent)
		: CustomButton(parent)
	{

	}
protected:
	void mousePressEvent(QMouseEvent *event)
	{
		event->ignore();	//让事件继续传播，CustomButtonEx的父组件CustomWidget也收到了这个事件，所以输出了自己的结果
		qDebug()<<"CustonButtonEx";
	}
};
//ustomButtonEx的父组件CustomWidget也收到了这个事件，所以输出了自己的结果。
// 同理，CustomWidget又没有调用父类函数或者显式设置accept()或ignore()，所以事件传播就此打住。
// 这里值得注意的是，CustomButtonEx的事件传播给了父组件CustomWidget，而不是它的父类CustomButton。
// 事件的传播是在组件层次上面的，而不是依靠类继承机制。

class CustomWidget : public QWidget
{
	Q_OBJECT
public:
	CustomWidget::CustomWidget(QWidget *parent)
		: QWidget(parent)
	{

	}
protected:
	void mousePressEvent(QMouseEvent *event)
	{
		QWidget::mousePressEvent(event);
		qDebug()<<"CustomWidget";
	}
};

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow::MainWindow(QWidget *parent = 0)
		: QMainWindow(parent)
	{
		CustomWidget *widget = new CustomWidget(this);
		CustomButton *cdex = new CustomButton(widget);
		cdex->setText(tr("CustomButton"));
		CustomButtonEx *cd = new CustomButtonEx(widget);
		cd->setText(tr("CustomButtonEx"));
		QVBoxLayout *widgetlayout = new QVBoxLayout(widget);
		widgetlayout->addWidget(cdex);
		widgetlayout->addWidget(cd);
		this->setCentralWidget(widget);
	}
protected:
	void mousePressEvent(QMouseEvent *event)
	{
		qDebug()<<"MainWindow";
	}
};

#endif // QT_ACCCEPT_IGNORE_H
