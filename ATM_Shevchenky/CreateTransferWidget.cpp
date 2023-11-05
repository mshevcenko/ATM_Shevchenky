#include "CreateTransferWidget.h"

CreateTransferWidget::CreateTransferWidget(QWidget* parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &CreateTransferWidget::closed);
}

CreateTransferWidget::~CreateTransferWidget()
{}