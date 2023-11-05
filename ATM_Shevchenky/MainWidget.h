#pragma once
#include "ui_main.h"

class MainWidget : public QWidget
{

    Q_OBJECT

public:
    MainWidget(QWidget* parent = nullptr);
    ~MainWidget();

signals:
    void withdrawal();
    void transfer();
    void creditLimit();
    void overflow();
    void transferHistory();
    void pickupCard();

private:
    Ui_Main ui;

    void tryPickupCard();
};