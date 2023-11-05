#include "OverflowCreditServicesListWidget.h"

OverflowCreditServicesListWidget::OverflowCreditServicesListWidget(QWidget* parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &OverflowCreditServicesListWidget::closed);
}

OverflowCreditServicesListWidget::~OverflowCreditServicesListWidget()
{}