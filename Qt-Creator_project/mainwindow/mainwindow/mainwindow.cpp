#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QDebug>
#include <QTextEdit>
#include <QFileDialog>
#include <QtGui>
#include <QWidget>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/images/file-open.png"), tr("&Open..."), this);
    openAction ->setShortcuts(QKeySequence::Open);
    openAction ->setStatusTip(tr("Open an existing file"));
    connect(openAction,&QAction::triggered, this, &MainWindow::openFile);

    saveAction = new QAction(QIcon(":/images/images/file-save.png"), tr("&Save..."), this);
	saveAction ->setShortcuts(QKeySequence::Save);
	saveAction ->setStatusTip(tr("Save a new file"));
    connect(saveAction,&QAction::triggered, this, &MainWindow::saveFile);

	QMenu *file = menuBar()->addMenu(tr("&File"));
	file ->addAction(openAction);
	file ->addAction(saveAction);

	QToolBar *toolBar = addToolBar(tr("&File"));
	toolBar ->addAction(openAction);
	toolBar ->addAction(saveAction);

	textEdit = new QTextEdit(this);
	setCentralWidget(textEdit);

    statusBar();

}

MainWindow::~MainWindow()
{
}

// void MainWindow::openFile()
// {
//     //QMessageBox::information(this, tr("Information"), tr("Open"));
//     QDialog dialog(this);
// //    dialog->setAttribute(Qt::WA_DeleteOnClose);
// //    dialog.setWindowTitle(tr("Hello,dialog!"));
// //    dialog.exec();
// //    qDebug()<< dialog.result();
//     //QDialog::exec()其返回值是QDialog::Accepted或者QDialog::Rejected
//     //判断对话框的返回值
//     if(dialog.exec() == QDialog::Accepted){
//         // do something
//         qDebug()<< tr("true");
//     }else{
//         // do something else
//         qDebug()<< tr("flase");
//     }
// 
// 	//自带的QMessageBox
// //    if (QMessageBox::Yes == QMessageBox::question(this,
// //                                                  tr("Question"),
// //                                                  tr("Are you OK"),
// //                                                  QMessageBox::Yes | QMessageBox::No,
// //                                                  QMessageBox::Yes)){
// //        QMessageBox::information(this, tr("Hmmm....."), tr("I'm glad to hear that!"));
// //    } else{
// //        QMessageBox::information(this, tr("Hmmm....."), tr("I'm sorry!"));
// //    }
// 	//自定义一个QMessageBox
// //     QMessageBox msgBox;
// //     msgBox.setText(tr("The document has been modifide."));
// //     msgBox.setInformativeText(tr("Do you want to save your changes?"));
// //     msgBox.setDetailedText(tr("Differencrs here...."));
// //     msgBox.setStandardButtons(QMessageBox::Save
// //                               | QMessageBox::Discard
// //                               | QMessageBox::Cancel);
// //     msgBox.setDefaultButton(QMessageBox::Save);
// //     int ret = msgBox.exec();
// //     switch (ret){
// //     case QMessageBox::Save:
// //         qDebug() <<"Save document!";
// //         break;
// //     case QMessageBox::Discard:
// //         qDebug() <<"Discard changes!";
// //         break;
// //     case QMessageBox::Cancel:
// //         qDebug() <<"Close document!";
// //         break;
// //     }
// 
// }


void MainWindow::openFile()
{
	// 使用QFileDialog::getOpenFileName()函数来获取需要打开的文件的路径，返回值是选择的文件路径
	/*
	QString getOpenFileName(QWidget * parent = 0,
							const QString & caption = QString(),
							const QString & dir = QString(),
							const QString & filter = QString(),
							QString * selectedFilter = 0,
							Options options = 0)
	parent：父窗口。我们前面介绍过，Qt 的标准对话框提供静态函数，用于返回一个模态对话框（在一定程度上这就是外观模式的一种体现）；
	caption：对话框标题；
	dir：对话框打开时的默认目录，“.” 代表程序运行目录，“/” 代表当前盘符的根目录（特指 Windows 平台；Linux 平台当然就是根目录），这个参数也可以是平台相关的，比如“C:\\”等；
	filter：过滤器。我们使用文件对话框可以浏览很多类型的文件，但是，很多时候我们仅希望打开特定类型的文件。比如，文本编辑器希望打开文本文件，图片浏览器希望打开图片文件。过滤器就是用于过滤特定的后缀名。如果我们使用“Image Files(*.jpg *.png)”，则只能显示后缀名是 jpg 或者 png 的文件。如果需要多个过滤器，使用“;;”分割，比如“JPEG Files(*.jpg);;PNG Files(*.png)”；
	selectedFilter：默认选择的过滤器；
	options：对话框的一些参数设定，比如只显示文件夹等等，它的取值是enum QFileDialog::Option，每个选项可以使用 | 运算组合起来。
	*/
	QString path = QFileDialog::getOpenFileName(this,
												tr("Open File"),
												".",
												tr("Text File(*.txt)"));
	if (!path.isEmpty()){
		QFile file(path);
		if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
			QMessageBox::warning(this,tr("Read File"),
				tr("Cannot open file:\n%1").arg(path));
			return;
		}
		QTextStream in(&file);
		textEdit->setText(in.readAll());
		file.close();
	} else {
		QMessageBox::warning(this, tr("Path"),
			tr("You did not select any file."));
	}
}

void MainWindow::saveFile()
{
	QString path = QFileDialog::getSaveFileName(this,
												tr("Open File"),
												".",
												tr("TExt File(*.txt)"));
	if(!path.isEmpty()){
		QFile file(path);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
			QMessageBox::warning(this, tr("Write File"),
				tr("Cannot open file:\n%1").arg(path));
			return;
		}
		QTextStream out(&file);
		// <<重定向，将QTextEdit的内容输出到一个文件中
		out << textEdit->toPlainText();
		file.close();
	} else {
		QMessageBox::warning(this, tr("Path"),
			tr("You did not select any file"));
	}
}


