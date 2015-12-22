#include <QApplication>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton button("Quit");
    // Qt 5
    //QObject::connect(&button, &QPushButton::clicked, &QApplication::quit);
    QObject::connect(&button, &QPushButton::clicked, [](bool){
        qDebug() <<"You clicked me!";
   });
    //Qt 4 的写法
  //  QObject::connect(&button,SIGNAL(clicked()),
  //                  &app,   SLOT(quit()));
    button.show();

    return app.exec();
}
