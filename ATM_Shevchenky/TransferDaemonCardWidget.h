#pragma once
#include "ui_transfer_daemon_card.h"
#include "TransferDaemon.h"

class ATM;

class TransferDaemonCardWidget : public QWidget
{
	Q_OBJECT

public:
	TransferDaemonCardWidget(ATM&, const TransferDaemon&, QWidget*parent = nullptr);
	~TransferDaemonCardWidget();

signals:
	void deleted(TransferDaemonCardWidget*);

private:
	ATM& _atm;
	TransferDaemon _transferDaemon;
	Ui_TransferDaemonCardWidgetClass ui;

	void changeActive(int state);
	void deleteTransferDaemon();
};
