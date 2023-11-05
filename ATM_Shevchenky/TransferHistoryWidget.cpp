#include "TransferHistoryWidget.h"

TransferHistoryWidget::TransferHistoryWidget(QWidget* parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &TransferHistoryWidget::closed);
}

TransferHistoryWidget::~TransferHistoryWidget()
{}