#include "user_signup_page.h"
#include <QApplication>
#include <QMessageBox>
#include "ui_user_signup_page.h"

User_SignUp_Page::User_SignUp_Page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User_SignUp_Page)
{
    ui->setupUi(this);
}

User_SignUp_Page::~User_SignUp_Page()
{
    delete ui;
}

void User_SignUp_Page::on_SignUp_Button_Clicked()
{
    QString username = ui->lineEdit_username->text();
    QString email = ui->lineEdit_email->text();
    QString password = ui->lineEdit_password->text();
    QString confirm_password = ui->lineEdit_confirm_password->text();

    // Check if any field is empty
    if (username.isEmpty() || email.isEmpty() || password.isEmpty() || confirm_password.isEmpty()) {
        QMessageBox::warning(this, "Signup", "Please fill in all fields");
        return;
    }
    // Check if passwords match
    if (password != confirm_password) {
        QMessageBox::warning(this, "Signup", "Passwords do not match");
        return;
    }

    // For no error
    ui->label_successful->setText("Account created successfully");

}

















