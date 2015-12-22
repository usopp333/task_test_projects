#include <QCoreApplication>

#include "newspaper.h"
#include "reader.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc,argv);

    Newsparper newsparper("Newsparper A");
    Reader reader;
    QObject::connect(&newsparper, &Newsparper::newPaper,
                     &reader, &Reader::receiveNewsparper);
    newsparper.send();

    return app.exec();
}
