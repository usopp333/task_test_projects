#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>

//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);

//    QPushButton button("Quit");
//    // Qt 5
//    //QObject::connect(&button, &QPushButton::clicked, &QApplication::quit);
//    QObject::connect(&button, &QPushButton::clicked, [](bool){
//        qDebug() <<"You clicked me!";
//   });
//    //Qt 4 的写法
//  //  QObject::connect(&button,SIGNAL(clicked()),
//  //                  &app,   SLOT(quit()));
//    button.show();

//    return app.exec();
//}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Enter your age");

    QSpinBox  *spinBox = new QSpinBox(&window);
    QSlider *slider = new QSlider(Qt::Horizontal, &window);
    spinBox->setRange(0,130);
    slider->setRange(0,130);

//    //Qt 5
//    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
//    void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
//    //QObject::connect(spinBox, &QSpinBox::valueChanged, slider, &QSlider::setValue);
//    QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);

    //Qt 4
    QObject::connect(slider,  SIGNAL(valueChanged(int)),
                        spinBox, SLOT(setValue(int)));
    QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                        slider,  SLOT(setValue(int)));
    spinBox->setValue(35);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    window.setLayout(layout);

    window.show();

    return app.exec();

}
