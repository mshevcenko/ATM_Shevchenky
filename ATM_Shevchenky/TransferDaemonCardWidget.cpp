#include <QDateTime>
#include <QMessageBox>
#include "TransferDaemonCardWidget.h"
#include "ATM.h"

TransferDaemonCardWidget::TransferDaemonCardWidget(ATM& atm, const TransferDaemon& transferDaemon, QWidget *parent):
	QWidget(parent),
	_atm(atm),
	_transferDaemon(transferDaemon)
{
	ui.setupUi(this);
	ui.targetLineEdit->setText(QString::fromStdString(_transferDaemon.to()));
	ui.ammountLineEdit->setText(QString::number(_transferDaemon.amount(), 'f', 2));
	ui.activeCheckBox->setChecked(_transferDaemon.isActive());
	ui.frequencyLineEdit->setText(QString::number(_transferDaemon.frequency()));
	ui.nextTransferDayLineEdit->setText(QDateTime::fromSecsSinceEpoch(_transferDaemon.nextTransferDate()).date().toString("dd.MM.yyyy"));
	connect(
		ui.deleteLabel,
		&ClickableLabel::clicked,
		this,
		&TransferDaemonCardWidget::deleteTransferDaemon
	);
	connect(
		ui.activeCheckBox,
		&QCheckBox::stateChanged,
		this,
		&TransferDaemonCardWidget::changeActive
	);
	//ui.
	//this->setLayout(ui.horizontalLayout);
}

TransferDaemonCardWidget::~TransferDaemonCardWidget()
{}

void TransferDaemonCardWidget::changeActive(int state)
{
	_transferDaemon.setActive(!_transferDaemon.isActive());
	_atm.editTransfer(_transferDaemon);
}

void TransferDaemonCardWidget::deleteTransferDaemon()
{
	QMessageBox msgBox;
	msgBox.setWindowTitle("Transfer daemon");
	msgBox.setText("Do you really want to delete transfer daemon?");
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.setDefaultButton(QMessageBox::Yes);
	int res = msgBox.exec();
	if (res == QMessageBox::Yes)
	{
		setVisible(false);
		_atm.deleteTransfer(_transferDaemon);
		emit deleted(this);
	}
}
