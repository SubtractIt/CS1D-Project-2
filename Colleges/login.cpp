#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_clicked()
{
    // Check for valid user and pass, if so then open the admin window
    if(ui->user->text() == "admin" && ui->pass->text() == "password") {
        Admin* adminFeatures = new Admin;
        adminFeatures -> setWindowTitle("Administrative Functions");
        adminFeatures -> show();
        this->close();
    } else {
        // Alerts if login failed
        QMessageBox::critical(this, "Login Failed", "Invalid username or password");
    }
}
