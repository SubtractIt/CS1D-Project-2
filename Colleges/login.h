#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "admin.h"
#include <QMessageBox>

namespace Ui {
class Login;
}

///
/// @brief Login class - handles logging in admin
///
class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    ///
    /// @brief Checks username and password and opens admin window if valid
    ///
    void on_login_clicked();

private:
    Ui::Login *ui;
};

#endif
