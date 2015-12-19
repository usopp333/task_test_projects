#include <QtGui>
#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)
	:QDialog(parent)
{
	label = new QLabel(tr("Find &what:"));
	lineEdit = new QLineEdit;
	label->setBuddy(lineEdit);

}