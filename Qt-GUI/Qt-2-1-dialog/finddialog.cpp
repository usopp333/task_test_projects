#include <QtGui>
#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)
	:QDialog(parent)
{
	//ÿһ���û��ɼ����ַ�����Χʹ��tr()����������һ����ϰ�ߣ� 
	// & ����ʾһ����ݼ�����ʹ��Alt+w����
	label = new QLabel(tr("Find &what:"));
	lineEdit = new QLineEdit;
	//��ǩ��飨buddy����һ�����ڲ��������㰴��Alt+wʱ�����㣨focus���ͻ��ƶ�������б༭�����ñ�ǩ�Ļ�飩�� 
	label->setBuddy(lineEdit);

	caseCheckBox = new QCheckBox(tr("Match &case"));
	backwardCheckBox = new QCheckBox(tr("Search &backward"));

	findButton = new QPushButton(tr("&Find"));
	//ͨ��setDefault(true);��find��ť��Ϊ�Ի����Ĭ�ϰ�ť��default button�����û�����Enter��ʱ�ܹ����¶�Ӧ�İ�ť
	findButton->setDefault(true);
	//��ֹ��find ��ʾΪ��ɫ
	findButton->setEnabled(false);

	closeButton = new QPushButton(tr("Close"));
	// �б༭���б仯������˽�в�enableFindButton
	connect(lineEdit,SIGNAL(textChanged(const QString &)),
		this,SLOT(enableFindButton(const QString &)));
	// ���find������˽�в�findClicked
	connect(findButton,SIGNAL(clicked()),
		this,SLOT(findClicked()));
	// ���close����close���رնԻ���
	connect(closeButton,SIGNAL(clicked()),
		this,SLOT(close()));
	// ��������Ƕ��
	QHBoxLayout *topLeftLayout = new QHBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(lineEdit);

	QVBoxLayout *leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topLeftLayout); //�Ӳ�����ӵ������֣��Ӳ��ֶ���ͻ��Զ������Լ��ĸ�����
	leftLayout->addWidget(caseCheckBox);
	leftLayout->addWidget(backwardCheckBox);

	QVBoxLayout *rightLayout = new QVBoxLayout;
	rightLayout->addWidget(findButton);
	rightLayout->addWidget(closeButton);
	rightLayout->addStretch(); //�ָ�������չ����ȷ����ť��ȫռ�ݲ���

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout); //�Ӳ�����ӵ�������
	mainLayout->addLayout(rightLayout); //�Ӳ�����ӵ�������
	//������װ���Ի��򣬳�Ϊ�Ի�����Ӷ������е��Ӵ��ڲ������¶����Լ��ĸ����󣬳�Ϊ�Ի�����Ӷ���
	setLayout(mainLayout); 

	setWindowTitle(tr("Find"));
	setFixedHeight(sizeHint().height());

}
// ���find��ť���ͻ����findClicked()�ۣ��òۻᷢ��findPrevious����������findNext����
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

// �б༭�����ı��ı�ͻ����enableFindButton()�ۣ�����б༭�������ı����ò۾ͻ�����Find��ť���������Find��ť
void FindDialog::enableFindButton(const QString &text)
{
	findButton->setEnabled(!text.isEmpty());
}