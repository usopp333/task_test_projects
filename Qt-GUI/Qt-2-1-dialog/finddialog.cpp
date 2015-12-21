#include <QtGui>
#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)
	:QDialog(parent)
{
	//每一个用户可见的字符串周围使用tr()函数（这是一个好习惯） 
	// & 来表示一个快捷键可是使用Alt+w激活
	label = new QLabel(tr("Find &what:"));
	lineEdit = new QLineEdit;
	//标签伙伴（buddy）：一个窗口部件，当你按下Alt+w时，焦点（focus）就会移动到这个行编辑器（该标签的伙伴）上 
	label->setBuddy(lineEdit);

	caseCheckBox = new QCheckBox(tr("Match &case"));
	backwardCheckBox = new QCheckBox(tr("Search &backward"));

	findButton = new QPushButton(tr("&Find"));
	//通过setDefault(true);让find按钮成为对话框的默认按钮（default button），用户按下Enter键时能够按下对应的按钮
	findButton->setDefault(true);
	//禁止了find 显示为灰色
	findButton->setEnabled(false);

	closeButton = new QPushButton(tr("Close"));
	// 行编辑器中变化，调用私有槽enableFindButton
	connect(lineEdit,SIGNAL(textChanged(const QString &)),
		this,SLOT(enableFindButton(const QString &)));
	// 点击find，调用私有槽findClicked
	connect(findButton,SIGNAL(clicked()),
		this,SLOT(findClicked()));
	// 点击close，调close，关闭对话框
	connect(closeButton,SIGNAL(clicked()),
		this,SLOT(close()));
	// 三个布局嵌套
	QHBoxLayout *topLeftLayout = new QHBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(lineEdit);

	QVBoxLayout *leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topLeftLayout); //子布局添加到父布局，子布局对象就会自动定义自己的父对象
	leftLayout->addWidget(caseCheckBox);
	leftLayout->addWidget(backwardCheckBox);

	QVBoxLayout *rightLayout = new QVBoxLayout;
	rightLayout->addWidget(findButton);
	rightLayout->addWidget(closeButton);
	rightLayout->addStretch(); //分隔符（伸展器）确保按钮完全占据布局

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout); //子布局添加到父布局
	mainLayout->addLayout(rightLayout); //子布局添加到父布局
	//主布局装到对话框，成为对话框的子对象，所有的子窗口部件重新定义自己的父对象，成为对话框的子对象
	setLayout(mainLayout); 

	setWindowTitle(tr("Find"));
	setFixedHeight(sizeHint().height());

}
// 点击find按钮，就会调用findClicked()槽，该槽会发射findPrevious（）或者是findNext（）
void FindDialog::findClicked()
{
	QString text = lineEdit->text();
	Qt::CaseSensitivity cs = 
		caseCheckBox->isChecked() ? Qt::CaseSensitive
							      : Qt::CaseInsensitive;
	if (backwardCheckBox->isChecked())
	{
		emit findPrevious(text,cs);
	}else{
		emit findNext(text,cs);
	}
}

// 行编辑器中文本改变就会调用enableFindButton()槽，如果行编辑器中有文本，该槽就会启用Find按钮。否则禁用Find按钮
void FindDialog::enableFindButton(const QString &text)
{
	findButton->setEnabled(!text.isEmpty());
}