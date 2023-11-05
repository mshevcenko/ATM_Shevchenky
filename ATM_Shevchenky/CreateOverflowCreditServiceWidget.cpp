#include "CreateOverflowCreditServiceWidget.h"

CreateOverflowCreditServiceWidget::CreateOverflowCreditServiceWidget(QWidget* parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &CreateOverflowCreditServiceWidget::closed);
}

CreateOverflowCreditServiceWidget::~CreateOverflowCreditServiceWidget()
{}