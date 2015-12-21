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
	//�������ж������źźͲ۵��࣬���ඨ�忪ʼ����Q_OBJECT�궼�Ǳ����  
	Q_OBJECT
public:
	FindDialog(QWidget *parent = 0);
signals:
	void findNext(const QString &str,Qt::CaseSensitivity cs);
	void findPrevious(const QString &str,Qt::CaseSensitivity cs);
//�źŲۣ�ͨ�����Ƶ����Ķ����������źŲ۵ĺ��������źŲ۵ĺ�����ֱ�ӵ����źŴ����� 
private slots:
	void findClicked();
	void enableFindButton(const QString &text);
//����һЩ˽�б���
private:
	QLabel *label;
	QLineEdit *lineEdit;
	QCheckBox *caseCheckBox;
	QCheckBox *backwardCheckBox;
	QPushButton *findButton;
	QPushButton *closeButton;

};
#endif