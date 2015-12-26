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
		event->ignore();	//���¼�����������CustomButtonEx�ĸ����CustomWidgetҲ�յ�������¼�������������Լ��Ľ��
		qDebug()<<"CustonButtonEx";
	}
};
//ustomButtonEx�ĸ����CustomWidgetҲ�յ�������¼�������������Լ��Ľ����
// ͬ��CustomWidget��û�е��ø��ຯ��������ʽ����accept()��ignore()�������¼������ʹ˴�ס��
// ����ֵ��ע����ǣ�CustomButtonEx���¼��������˸����CustomWidget�����������ĸ���CustomButton��
// �¼��Ĵ�����������������ģ�������������̳л��ơ�

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
