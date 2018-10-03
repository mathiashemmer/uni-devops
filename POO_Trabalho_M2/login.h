#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    bool ValidadePassword(std::string log, std::string pass);
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btn_Login_clicked();

private:
    std::string credenciais;
    Ui::Login *ui;
};

#endif // LOGIN_H
