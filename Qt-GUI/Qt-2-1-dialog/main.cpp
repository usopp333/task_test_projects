#include <QApplication>
#include "finddialog.h"

//////////////////////////////////////////////////////////////////////////
//�����Ի���Ļ������裺
//1.��������ʼ���Ӵ��ڲ�����
//2.���Ӵ��ڲ����ŵ�������
//3.����Tab��˳��
//4.�����ź�-��֮�������
//5.ʵ�ֶԻ����е��Զ����
//////////////////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);
	FindDialog *dialog = new FindDialog;
	dialog->show();
	return app.exec();
}