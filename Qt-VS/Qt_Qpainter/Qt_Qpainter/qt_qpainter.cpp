#include "qt_qpainter.h"

PainteWidget::PainteWidget(QWidget *parent):
	QWidget(parent)
{
		resize(800,600);
		setWindowTitle(tr("Paint Demo"));
}

// void PainteWidget::paintEvent(QPaintEvent *)
// {
// 	QPainter painter(this);
// 	painter.drawLine(80,100,650,500);
// 	painter.setPen(Qt::red);
// 	painter.drawRect(10,10,100,400);
// 	painter.setPen(QPen(Qt::green,5));
// 	painter.setBrush(Qt::blue);
// 	painter.drawEllipse(50,150,400,200);
// }

// 不抗锯齿和抗锯齿的两个椭圆（反走样）
// void PainteWidget::paintEvent(QPaintEvent *)
// {
// 	QPainter painter(this);
// 	painter.setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
// 	painter.setBrush(Qt::yellow);
// 	painter.drawEllipse(50, 150, 200, 150);
// 
// 	painter.setRenderHint(QPainter::Antialiasing, true);
// 	painter.setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
// 	painter.setBrush(Qt::yellow);
// 	painter.drawEllipse(300, 150, 200, 150);
// }

//使用渐变进行填充
void PainteWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	//在从 (60, 50) 到 (200, 200) 的线段上，
	// 在 0.2，也就五分之一处设置成白色，
	// 在 0.6 也就是五分之三处设置成绿色，
	// 在 1.0 也就是终点处设置成黑色。
	painter.setRenderHint(QPainter::Antialiasing, true);
	QLinearGradient linearGradient(60, 50, 200, 200);
	linearGradient.setColorAt(0.2, Qt::white);
	linearGradient.setColorAt(0.6, Qt::green);
	linearGradient.setColorAt(1.0, Qt::black);
	painter.setBrush(QBrush(linearGradient));
	painter.drawEllipse(50, 50, 200, 150);
}

// 绘制一个色轮
ColorWheel::ColorWheel(QWidget *parent):
QWidget(parent)
{
	resize(800,600);
	setWindowTitle(tr("Paint Demo"));
}
void ColorWheel::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	const int r = 150;
	QConicalGradient conicalGradient(0, 0, 0);

	conicalGradient.setColorAt(0.0, Qt::red);
	conicalGradient.setColorAt(60.0/360.0, Qt::yellow);
	conicalGradient.setColorAt(120.0/360.0, Qt::green);
	conicalGradient.setColorAt(180.0/360.0, Qt::cyan);
	conicalGradient.setColorAt(240.0/360.0, Qt::blue);
	conicalGradient.setColorAt(300.0/360.0, Qt::magenta);
	conicalGradient.setColorAt(1.0, Qt::red);

	painter.translate(r, r);

	QBrush brush(conicalGradient);
	painter.setPen(Qt::NoPen);
	painter.setBrush(brush);
	painter.drawEllipse(QPoint(0, 0), r, r);
}