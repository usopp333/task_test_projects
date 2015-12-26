#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

class QTextEdit;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	private slots:
		void openFile();
		void saveFile();

private:
	QAction *openAction;
	QAction *saveAction;

	QTextEdit *textEdit;
protected:
	void MainWindow::closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
