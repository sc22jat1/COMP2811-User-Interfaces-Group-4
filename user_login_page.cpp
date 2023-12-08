// user_login_page.cpp

#include "user_login_page.h"
#include "ui_user_login_page.h"
#include <QVBoxLayout>
#include <qmessagebox>

User_Login_Page::User_Login_Page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User_Login_Page)
{
    ui->setupUi(this);

    // Connect the handleLoginButtonClicked() slot when the login button is clicked
    connect(ui->Login_Button, &QPushButton::clicked, this, &User_Login_Page::on_Login_Button_Clicked);
}

User_Login_Page::~User_Login_Page()
{
    delete ui;
}


void User_Login_Page::on_Login_Button_Clicked()
{
    //Test ID and Password
    QString validUsername = "admin";
    QString validPassword = "admin123";

    QString username = ui->UserName->text();  // 수정: 사용자 이름 필드에서 텍스트 가져오기
    QString password = ui->Password->text();  // 수정: 비밀번호 필드에서 텍스트 가져오기

    if (username == validUsername && password == validPassword) {
        emit login_Successful();
        hide();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password. Please try again.");
    }
}
