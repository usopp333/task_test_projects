#include <QApplication>
#include "finddialog.h"

//////////////////////////////////////////////////////////////////////////
//创建对话框的基本步骤：
//1.创建并初始化子窗口部件；
//2.把子窗口部件放到布局中
//3.设置Tab键顺序
//4.建立信号-槽之间的连接
//5.实现对话框中的自定义槽
//////////////////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);
	FindDialog *dialog = new FindDialog;
	dialog->show();
	return app.exec();
}