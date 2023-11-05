#pragma once
#include "ui_overflow.h"

class OverflowWidget : public QWidget
{

    Q_OBJECT

public:
    OverflowWidget(QWidget* parent = nullptr);
    ~OverflowWidget();

signals:
    void overflowService();
    void createOverflowCreditService();
    void overflowCreditServicesList();
    void closed();

private:
    Ui_Overflow ui;
};