#include <QtGui>
#include <QtWidgets>
#include "mainwindow_new.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent)
{
	openAction = new QAction(QIcon(":/images/images/file-open.png"), tr("&Open..."), this);
	openAction->setShortcuts(QKeySequence::Open);
	openAction->setStatusTip(tr("Open an existing file"));
	connect(openAction, &QAction::triggered, this, &MainWindow::openFile);

	saveAction = new QAction(QIcon(":/images/images/file-save"), tr("&Save..."), this);
	saveAction->setShortcuts(QKeySequence::Save);
	saveAction->setStatusTip(tr("Save a new file"));
	connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);

	QMenu *file = menuBar()->addMenu(tr("&File"));
	file->addAction(openAction);
	file->addAction(saveAction);

	QToolBar *toolBar = addToolBar(tr("&File"));
	toolBar->addAction(openAction);
	toolBar->addAction(saveAction);

	textEdit = new QTextEdit(this);
	setCentralWidget(textEdit);
	//setWindowTitle()函数可以使用 [*] 这种语法来表明，
	// 在窗口内容发生改变时（通过setWindowModified(true)函数通知），
	// Qt 会自动在标题上面的 [*] 位置替换成 * 号
	connect(textEdit, &QTextEdit::textChanged, [=](){
		this->setWindowModified(true);
	});

	setWindowTitle("TextPad[*]");
}

MainWindow::~MainWindow()
{
}

//	首先判断是不是有过修改，如果有，则弹出询问框，问一下是否要退出。
//	如果用户点击了“Yes”，则接受关闭事件，这个事件所在的操作就是关闭窗口
void MainWindow :: closeEvent(QCloseEvent *event)
{
	if(isWindowModified()){
		bool exit = QMessageBox::question(this,
										tr("Quit"),
										tr("Are you sure to quit this qpplication?"),
										QMessageBox::Yes | QMessageBox::No,
										QMessageBox::No ) == QMessageBox::Yes ;
		if(exit){
			event->accept();
		} else{
			event->ignore();
		}
	} else{
		event->accept();
	}
}

void MainWindow::openFile()
{
	QString path = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Text Files(*.txt)"));
	if(!path.isEmpty()) {
		QFile file(path);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QMessageBox::warning(this, tr("Read File"), tr("Cannot open file:\n%1").arg(path));
			return;
		}
		QTextStream in(&file);
		textEdit->setText(in.readAll());
		file.close();
	} else {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any file."));
	}
}

void MainWindow::saveFile()
{
	QString path = QFileDialog::getSaveFileName(this, tr("Save File"), ".", tr("Text Files(*.txt)"));
	if(!path.isEmpty()) {
		QFile file(path);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
			QMessageBox::warning(this, tr("Write File"), tr("Cannot open file:\n%1").arg(path));
			return;
		}
		QTextStream out(&file);
		out << textEdit->toPlainText();
		file.close();
	} else {
		QMessageBox::warning(this, tr("Path"), tr("You did not select any file."));
	}
}
