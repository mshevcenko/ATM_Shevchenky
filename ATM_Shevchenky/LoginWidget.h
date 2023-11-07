#pragma once
#include "ui_login.h"

class ATM;

class LoginWidget : public QWidget
{

    Q_OBJECT

public:
    LoginWidget(ATM& atm, QWidget* parent = nullptr);
    ~LoginWidget();

    void updateData();

signals:
    void login();

private:
    ATM& _atm;
    Ui_Login ui;
    void tryLogin();
};