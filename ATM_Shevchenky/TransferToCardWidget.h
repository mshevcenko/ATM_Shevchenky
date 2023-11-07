#pragma once
#include "ui_transfer_to_card.h"
#include "Transfer.h"

class TransferToCardWidget : public QWidget
{
	Q_OBJECT

public:
	TransferToCardWidget(const Transfer&, QWidget* parent = nullptr);
	~TransferToCardWidget();

private:
	Transfer _transfer;
	Ui_TransferToCard ui;
};