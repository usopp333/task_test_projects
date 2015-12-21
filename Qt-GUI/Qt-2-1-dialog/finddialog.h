#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qpushbutton.h>
#include <qboxlayout.h>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog
{
	//对于所有定义了信号和槽的类，在类定义开始处的Q_OBJECT宏都是必需的  
	Q_OBJECT
public:
	FindDialog(QWidget *parent = 0);
signals:
	void findNext(const QString &str,Qt::CaseSensitivity cs);
	void findPrevious(const QString &str,Qt::CaseSensitivity cs);
//信号槽：通常类似单击的动作会引发信号槽的函数，而信号槽的函数会直接调用信号处理函数 
private slots:
	void findClicked();
	void enableFindButton(const QString &text);
//定义一些私有变量
private:
	QLabel *label;
	QLineEdit *lineEdit;
	QCheckBox *caseCheckBox;
	QCheckBox *backwardCheckBox;
	QPushButton *findButton;
	QPushButton *closeButton;

};
#endif