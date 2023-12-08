#ifndef USER_LOGIN_PAGE_H
#define USER_LOGIN_PAGE_H

#include <QWidget>
#include <qpushbutton>
#include <QLineEdit>

namespace Ui {
class User_Login_Page;
}

class User_Login_Page : public QWidget
{
    Q_OBJECT

public:
    explicit User_Login_Page(QWidget *parent = nullptr);
    ~User_Login_Page();

signals:
    void login_Successful();

private:
    Ui::User_Login_Page *ui;
    QLineEdit *idLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;

private slots:
    // connector to mainpage
    void on_Login_Button_Clicked();
};

#endif // USER_LOGIN_PAGE_H
