#include "CreateTransferDaemonWidget.h"

CreateTransferDaemonWidget::CreateTransferDaemonWidget(QWidget* parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &CreateTransferDaemonWidget::closed);
}

CreateTransferDaemonWidget::~CreateTransferDaemonWidget()
{}