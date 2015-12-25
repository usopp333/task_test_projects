#include "qt_custombutton.h"

CustomButton::CustomButton(QWidget *parent) :
	QPushButton(parent)
{
	connect(this, &CustomButton::clicked,
			this, &CustomButton::onButtonCilecked);
}

void CustomButton::onButtonCilecked()
{
	qDebug()<<"You clicked this!";
}

//��д��CustomButton��mousePressEvent()����
// ����д�¼��ص�����ʱ��ʱ��ע���Ƿ���Ҫͨ�����ø����ͬ��������ȷ��ԭ��ʵ�����ܽ���
// ��ô���Ǻ�����clicked()�ź���Զ���ᷢ���������ӵ�����źŵĲۺ���Ҳ����Զ���ᱻִ�С�
// ���ϣ�������¼�����ν���ԣ���ָ�Լ�����Ҫ����¼�����ֻҪ���ø������Ӧ�������ɡ�
// Qt �е��¼����� protected �ģ���ˣ���д�ĺ����ض��������丸���е���Ӧ���������ԣ���������ǿ��е�
void CustomButton::mousePressEvent(QMouseEvent *event)
{
	//�ж������갴�µ�����������ӡ������left���ַ��������򣬵��ø����ͬ��������
	if(event->button() == Qt::LeftButton){
		qDebug()<<"left";
		} else {
			    QPushButton::mousePressEvent(event);
			}	
				
}

