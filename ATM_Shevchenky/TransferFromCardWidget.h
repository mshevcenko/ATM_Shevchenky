#pragma once
#include "ui_transfer_from_card.h"
#include "Transfer.h"

class TransferFromCardWidget : public QWidget
{
	Q_OBJECT

public:
	TransferFromCardWidget(const Transfer&, QWidget* parent = nullptr);
	~TransferFromCardWidget();

private:
	Transfer _transfer;
	Ui_TransferFromCard ui;
};