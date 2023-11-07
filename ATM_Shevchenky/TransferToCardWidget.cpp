#include <QDateTime>
#include "TransferToCardWidget.h"

TransferToCardWidget::TransferToCardWidget(const Transfer& transfer, QWidget* parent) :
	QWidget(parent),
	_transfer(transfer)
{
	ui.setupUi(this);
	ui.toLineEdit->setText(QString::fromStdString(_transfer.to()));
	ui.ammountLineEdit->setText(QString::number(_transfer.amount(), 'f', 2));
	ui.dateLineEdit->setText(QDateTime::fromSecsSinceEpoch(_transfer.transferDate()).date().toString("dd.MM.yyyy"));
}

TransferToCardWidget::~TransferToCardWidget()
{}