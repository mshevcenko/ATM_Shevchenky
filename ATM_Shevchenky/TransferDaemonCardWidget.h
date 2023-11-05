#pragma once
#include "ui_transfer_daemon_card.h"

class TransferDaemonCardWidget : public QWidget
{
	Q_OBJECT

public:
	TransferDaemonCardWidget(QWidget*parent = nullptr);
	~TransferDaemonCardWidget();

private:
	Ui_TransferDaemonCardWidgetClass ui;
};
