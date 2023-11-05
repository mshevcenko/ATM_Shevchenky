#pragma once
#include "ui_overflow_service.h"

class OverflowServiceWidget : public QWidget
{

    Q_OBJECT

public:
    OverflowServiceWidget(QWidget* parent = nullptr);
    ~OverflowServiceWidget();

signals:
    void closed();

private:
    Ui_OverflowService ui;
};