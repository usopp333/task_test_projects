/*
下面总结一下自定义信号槽需要注意的事项：

    发送者和接收者都需要是QObject的子类（当然，槽函数是全局函数、Lambda 表达式等无需接收者的时候除外）；
    使用 signals 标记信号函数，信号是一个函数声明，返回 void，不需要实现函数代码；
    槽函数是普通的成员函数，作为成员函数，会受到 public、private、protected 的影响；
    使用 emit 在恰当的位置发送信号；
    使用QObject::connect()函数连接信号和槽。
 */
#include <QCoreApplication>

#include "newspaper.h"
#include "reader.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc,argv);

    Newsparper newsparper("Newsparper A");
    Reader reader;
	//Qt 5
// 	void (Newsparper:: *newPaperNameDate)(const QString &,const QDate &) = &Newsparper::newPaper;
//     QObject::connect(&newsparper, newPaperNameDate,
//                      &reader, &Reader::receiveNewsparper);
	QObject::connect(&newsparper,
		static_cast<void(Newsparper:: *)(const QString &, const QDate &)>(&Newsparper::newPaper),
		&reader,
		&Reader::receiveNewsparper);
	
	
	
	//Qt 4
// 	QObject::connect(&newsparper, SIGNAL(newPaper(QString,QDate)),
// 		&reader, SLOT(receiveNewsparper(QString,QDate)));


    newsparper.send();

    return app.exec();
}
