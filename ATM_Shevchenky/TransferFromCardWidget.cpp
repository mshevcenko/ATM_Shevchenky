#include <QDateTime>
#include "TransferFromCardWidget.h"

TransferFromCardWidget::TransferFromCardWidget(const Transfer& transfer, QWidget* parent):
	QWidget(parent),
	_transfer(transfer)
{
	ui.setupUi(this);
	ui.fromLineEdit->setText(QString::fromStdString(_transfer.from()));
	ui.ammountLineEdit->setText(QString::number(_transfer.amount(), 'f', 2));
	ui.dateLineEdit->setText(QDateTime::fromSecsSinceEpoch(_transfer.transferDate()).date().toString("dd.MM.yyyy"));
}

TransferFromCardWidget::~TransferFromCardWidget()
{}