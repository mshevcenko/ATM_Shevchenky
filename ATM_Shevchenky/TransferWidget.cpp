#include "TransferWidget.h"

TransferWidget::TransferWidget(QWidget* parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    connect(
        ui.createTransferButton, 
        &QPushButton::clicked, 
        this,
        &TransferWidget::createTransfer);
    connect(
        ui.createTransferDaemonButton, 
        &QPushButton::clicked, 
        this,
        &TransferWidget::createTransferDaemon);
    connect(ui.transferDaemonsListButton, 
        &QPushButton::clicked, 
        this,
        &TransferWidget::transferDaemonsList);
    connect(
        ui.closeButton, 
        &ClickableLabel::clicked, 
        this,
        &TransferWidget::closed);
}

TransferWidget::~TransferWidget()
{}