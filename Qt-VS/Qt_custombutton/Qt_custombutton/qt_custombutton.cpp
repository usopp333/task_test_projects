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

//重写了CustomButton的mousePressEvent()函数
// 当重写事件回调函数时，时刻注意是否需要通过调用父类的同名函数来确保原有实现仍能进行
// 这么覆盖函数，clicked()信号永远不会发生，你连接到这个信号的槽函数也就永远不会被执行。
// 如果希望忽略事件（所谓忽略，是指自己不想要这个事件），只要调用父类的响应函数即可。
// Qt 中的事件都是 protected 的，因此，重写的函数必定存在着其父类中的响应函数，所以，这个方法是可行的
// 如果子类没有处理这个事件，就会继续向其父类传递
// 如果一个事件处理函数调用了一个事件对象的accept()函数，这个事件就不会被继续传播给其父组件；如果它调用了事件的ignore()函数，Qt 会从其父组件中寻找另外的接受者。
// Qt 做了特殊的设计：事件对象默认是 accept 的，而作为所有组件的父类QWidget的默认实现则是调用ignore()。
void CustomButton::mousePressEvent(QMouseEvent *event)
{
	//判断如果鼠标按下的是左键，则打印出来“left”字符串，否则，调用父类的同名函数。
	if(event->button() == Qt::LeftButton){
		qDebug()<<"left";
		} else {
			    QPushButton::mousePressEvent(event);
			}	
				
}

