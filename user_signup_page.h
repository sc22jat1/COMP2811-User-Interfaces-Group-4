#ifndef USER_SIGNUP_PAGE_H
#define USER_SIGNUP_PAGE_H

#include <QWidget>

namespace Ui {
class User_SignUp_Page;
}

class User_SignUp_Page : public QWidget
{
    Q_OBJECT

public:
    explicit User_SignUp_Page(QWidget *parent = nullptr);
    ~User_SignUp_Page();

private slots:

    void on_SignUp_Button_Clicked();

private:
    Ui::User_SignUp_Page *ui;
};

#endif // USER_SIGNUP_PAGE_H
