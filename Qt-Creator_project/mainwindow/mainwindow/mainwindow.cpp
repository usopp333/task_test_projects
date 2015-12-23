#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QDebug>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/doc-open"),tr("&Open. . ."),this);
    openAction ->setShortcuts(QKeySequence::Open);
    openAction ->setStatusTip(tr("Open an existing file"));
    connect(openAction,&QAction::triggered, this, &MainWindow::open);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file ->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar ->addAction(openAction);

    QToolBar *toolBar2 = addToolBar(tr("&Tool Bar 2"));
    toolBar2 ->addAction(openAction);

    statusBar();

}

MainWindow::~MainWindow()
{
}

void MainWindow::open()
{
    //QMessageBox::information(this, tr("Information"), tr("Open"));
    QDialog dialog(this);
//    dialog->setAttribute(Qt::WA_DeleteOnClose);
//    dialog.setWindowTitle(tr("Hello,dialog!"));
//    dialog.exec();
//    qDebug()<< dialog.result();
    //QDialog::exec()其返回值是QDialog::Accepted或者QDialog::Rejected
    //判断对话框的返回值
    if(dialog.exec() == QDialog::Accepted){
        // do something
        qDebug()<< tr("true");
    }else{
        // do something else
        qDebug()<< tr("flase");
    }


//    if (QMessageBox::Yes == QMessageBox::question(this,
//                                                  tr("Question"),
//                                                  tr("Are you OK"),
//                                                  QMessageBox::Yes | QMessageBox::No,
//                                                  QMessageBox::Yes)){
//        QMessageBox::information(this, tr("Hmmm....."), tr("I'm glad to hear that!"));
//    } else{
//        QMessageBox::information(this, tr("Hmmm....."), tr("I'm sorry!"));
//    }
    QMessageBox msgBox;
    msgBox.setText(tr("The document has been modifide."));
    msgBox.setInformativeText(tr("Do you want to save your changes?"));
    msgBox.setDetailedText(tr("Differencrs here...."));
    msgBox.setStandardButtons(QMessageBox::Save
                              | QMessageBox::Discard
                              | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret){
    case QMessageBox::Save:
        qDebug() <<"Save document!";
        break;
    case QMessageBox::Discard:
        qDebug() <<"Discard changes!";
        break;
    case QMessageBox::Cancel:
        qDebug() <<"Close document!";
        break;
    }

}
