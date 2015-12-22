#include <QObject>
#include <QDebug>

class Reader : public QObject
{
    Q_OBJECT
public:
    Reader() {}
    void receiveNewsparper(const QString & name)
    {
        qDebug() <<"Receives Newsparper: "<< name;
    }

};
