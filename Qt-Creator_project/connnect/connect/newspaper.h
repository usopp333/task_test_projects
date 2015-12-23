#include <QObject>
// Newsparper 类
class Newsparper : public QObject   //为了使用槽信号，必须继承QObject
{
    Q_OBJECT    //凡是QObject类必须添加这个宏（放在头文件中moc处理，这也是为什么newsparper.h和reader.h不能放到cpp中main的前面的原因）
public:
    Newsparper(const QString & name) :
        m_name(name)
    {
    }
    void send()
    {
        //emit Qt 对C++的扩展（关键字，也是宏），含义“发出”，发出newPaper()信号
        emit newPaper(m_name);
    }
signals:
    void newPaper(const QString &name);
	void newPaper(const QString &name,const QDate &date);
private:
    QString m_name;

};
