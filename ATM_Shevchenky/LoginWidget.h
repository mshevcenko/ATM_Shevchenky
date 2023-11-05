#pragma once
#include "ui_login.h"

class LoginWidget : public QWidget
{

    Q_OBJECT

public:
    LoginWidget(QWidget* parent = nullptr);
    ~LoginWidget();

signals:
    void login();

private:
    Ui_Login ui;
    void tryLogin();
};