//////////////////////////////////////////////////////////////////
//
// Qt �Ļ�ͼϵͳ
// 
// Qt �Ļ�ͼϵͳʵ�����ǣ�ʹ��QPainter��QPainterDevice�Ͻ��л��ƣ�
// ����֮��ʹ��QPaintEngine����ͨѶ��Ҳ���Ƿ���QPainter��ָ���
// 
//////////////////////////////////////////////////////////////////

#include "qt_qpainter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//PainteWidget w;
	ColorWheel w; //����һ��ɫ��
	w.show();
	return a.exec();
}
