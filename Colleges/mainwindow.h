#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QMovie>
#include "login.h"
#include "trip.h"
#include "display.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


///
/// @brief The MainWindow class - application main window
///
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ///
    /// @brief MainWindow - initialize window
    ///
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    ///
    /// @brief Show login screen
    ///
    void on_adminLogin_clicked();

    ///
    /// @brief Show trips screen
    ///
    void on_pushButton_clicked();

    ///
    /// @brief Show display screen
    ///
    void on_display_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
