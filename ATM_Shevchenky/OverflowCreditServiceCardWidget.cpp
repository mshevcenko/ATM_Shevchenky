#include <QMessageBox>
#include "OverflowCreditServiceCardWidget.h"
#include "ATM.h"

OverflowCreditServiceCardWidget::OverflowCreditServiceCardWidget(ATM& atm, const OverflowCreditService& overflowCreditService, QWidget* parent) :
	QWidget(parent),
	_atm(atm),
	_overflowCreditService(overflowCreditService)
{
	ui.setupUi(this);
	ui.targetLineEdit->setText(QString::fromStdString(_overflowCreditService.to()));
	ui.ammountLineEdit->setText(QString::number(_overflowCreditService.amount(), 'f', 2));
	connect(
		ui.deleteLabel,
		&ClickableLabel::clicked,
		this,
		&OverflowCreditServiceCardWidget::deleteOverflowCreditService
	);
}

OverflowCreditServiceCardWidget::~OverflowCreditServiceCardWidget()
{}

void OverflowCreditServiceCardWidget::deleteOverflowCreditService()
{
	QMessageBox msgBox;
	msgBox.setWindowTitle("Overflow credit service");
	msgBox.setText("Do you really want to delete overflow credit service?");
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.setDefaultButton(QMessageBox::Yes);
	int res = msgBox.exec();
	if (res == QMessageBox::Yes)
	{
		setVisible(false);
		_atm.deleteOverflowCreditService(_overflowCreditService);
		emit deleted(this);
	}
}