#include "OverflowServiceWidget.h"

OverflowServiceWidget::OverflowServiceWidget(QWidget* parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &OverflowServiceWidget::closed);
}

OverflowServiceWidget::~OverflowServiceWidget()
{}