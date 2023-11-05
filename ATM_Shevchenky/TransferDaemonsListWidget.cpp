#include "TransferDaemonsListWidget.h"

TransferDaemonsListWidget::TransferDaemonsListWidget(QWidget* parent):
    QWidget(parent)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &TransferDaemonsListWidget::closed);
}

TransferDaemonsListWidget::~TransferDaemonsListWidget()
{}