#include "qt_event_event.h"
#include <QtWidgets/QApplication>
//���ǿ����ܽ�һ�� Qt ���¼�����ʵ�������������Σ�
//1.��дpaintEvent()��mousePressEvent()���¼�����������������ͨ����򵥵���ʽ��ͬʱ����Ҳ��򵥡�
//2.��дevent()������event()���������ж�����¼���ڣ�QObject��QWidget�е�ʵ�֣�Ĭ���ǰ��¼����ݸ��ض����¼���������
//3.���ض��������氲װ�¼����������ù����������˸ö�����յ����¼���
//4.��QCoreApplication::instance()���氲װ�¼���������
//  �ù��������������ж���������¼�����˺�notify()����һ��ǿ�󣬵�����������Ϊ���԰�װ�����������
//  ȫ�ֵ��¼����������Կ��� disabled ������淢��������¼���ȫ�ֹ�������һ�����⣺ֻ���������̡߳�
//5.��дQCoreApplication::notify()������������ǿ��ģ���ȫ���¼�������һ���ṩ��ȫ���ƣ����Ҳ����̵߳����ơ�
//  ����ȫ�ַ�Χ��ֻ����һ����ʹ�ã���ΪQCoreApplication�ǵ����ģ���

//ȫ���¼�����������һ�����ã�֮���Ǹö���������¼��������������event()������������ض����¼���������
// int main(int argc, char *argv[])
// {
// 	QApplication a(argc, argv);
// 	CustomWidget w;
// 	w.show();
// 	return a.exec();
// }

// �¼�����������EventFilter
// int main(int argc, char *argv[])
// {
// 	QApplication a(argc, argv);
// 	MainWindow w;
// 	w.show();
// 	return a.exec();
// }

// // �����¼�����ʽ�ĵ���˳��
int main(int argc,char *argv[])
{
	QApplication app(argc,argv);
	Label label;
	app.installEventFilter(new EventFilter(&label,&label));
	label.show();

	return app.exec();
}