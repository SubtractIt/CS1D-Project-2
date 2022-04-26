/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *adminLogin;
    QPushButton *pushButton;
    QPushButton *display;
    QLabel *bannerPhoto;
    QLabel *find;
    QLabel *your;
    QLabel *future;
    QLabel *confetti;
    QLabel *sponsor;
    QLabel *sorority;
    QLabel *deltathetalambda;
    QLabel *sororityValues;
    QFrame *frame;
    QWidget *widget;
    QLabel *copyright;
    QLabel *legals;
    QLabel *socials;
    QLabel *links;
    QLabel *topics;
    QLabel *ourstory;
    QLabel *story;
    QLabel *fb;
    QLabel *insta;
    QLabel *pinoodle;
    QLabel *linkedin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(611, 900);
        MainWindow->setMinimumSize(QSize(611, 900));
        MainWindow->setMaximumSize(QSize(611, 900));
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        adminLogin = new QPushButton(centralwidget);
        adminLogin->setObjectName(QString::fromUtf8("adminLogin"));
        adminLogin->setGeometry(QRect(320, 430, 261, 121));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Lohit Devanagari"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        adminLogin->setFont(font1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/lit_frat_party.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        adminLogin->setIcon(icon);
        adminLogin->setIconSize(QSize(165, 165));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 280, 261, 121));
        pushButton->setFont(font1);
        pushButton->setLayoutDirection(Qt::LeftToRight);
        pushButton->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/College-forum-stock.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(165, 165));
        display = new QPushButton(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(20, 280, 261, 121));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Lohit Devanagari"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        display->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/microscope.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        display->setIcon(icon2);
        display->setIconSize(QSize(165, 165));
        bannerPhoto = new QLabel(centralwidget);
        bannerPhoto->setObjectName(QString::fromUtf8("bannerPhoto"));
        bannerPhoto->setGeometry(QRect(0, 0, 621, 261));
        bannerPhoto->setPixmap(QPixmap(QString::fromUtf8(":/bannerPhoto.jpg")));
        find = new QLabel(centralwidget);
        find->setObjectName(QString::fromUtf8("find"));
        find->setGeometry(QRect(10, 10, 191, 81));
        QFont font3;
        font3.setFamily(QString::fromUtf8("URW Bookman"));
        font3.setPointSize(50);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        find->setFont(font3);
        find->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #fff;\n"
"	line-height: 0.5;\n"
"}"));
        your = new QLabel(centralwidget);
        your->setObjectName(QString::fromUtf8("your"));
        your->setGeometry(QRect(10, 90, 191, 81));
        your->setFont(font3);
        your->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #fff;\n"
"	line-height: 0.5;\n"
"}"));
        future = new QLabel(centralwidget);
        future->setObjectName(QString::fromUtf8("future"));
        future->setGeometry(QRect(10, 160, 251, 81));
        QFont font4;
        font4.setFamily(QString::fromUtf8("URW Bookman"));
        font4.setPointSize(42);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        future->setFont(font4);
        future->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #fff;\n"
"	line-height: 0.5;\n"
"}"));
        confetti = new QLabel(centralwidget);
        confetti->setObjectName(QString::fromUtf8("confetti"));
        confetti->setGeometry(QRect(20, 430, 251, 111));
        sponsor = new QLabel(centralwidget);
        sponsor->setObjectName(QString::fromUtf8("sponsor"));
        sponsor->setGeometry(QRect(20, 420, 261, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Lohit Devanagari"));
        font5.setBold(true);
        font5.setWeight(75);
        sponsor->setFont(font5);
        sorority = new QLabel(centralwidget);
        sorority->setObjectName(QString::fromUtf8("sorority"));
        sorority->setGeometry(QRect(90, 450, 151, 51));
        QFont font6;
        font6.setPointSize(35);
        font6.setBold(true);
        font6.setWeight(75);
        sorority->setFont(font6);
        sorority->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(255, 122, 225)\n"
"};"));
        deltathetalambda = new QLabel(centralwidget);
        deltathetalambda->setObjectName(QString::fromUtf8("deltathetalambda"));
        deltathetalambda->setGeometry(QRect(80, 500, 141, 17));
        deltathetalambda->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(255, 122, 225)\n"
"};"));
        sororityValues = new QLabel(centralwidget);
        sororityValues->setObjectName(QString::fromUtf8("sororityValues"));
        sororityValues->setGeometry(QRect(70, 520, 161, 17));
        sororityValues->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(255, 122, 225)\n"
"};"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 570, 611, 311));
        frame->setStyleSheet(QString::fromUtf8("QFramel {\n"
"background-color: rgb(0, 0, 0)\n"
"};"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-10, -10, 631, 331));
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background-color: rgb(85, 87, 83)\n"
"}"));
        copyright = new QLabel(widget);
        copyright->setObjectName(QString::fromUtf8("copyright"));
        copyright->setGeometry(QRect(30, 30, 231, 16));
        copyright->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(255, 255, 255)\n"
"}"));
        legals = new QLabel(widget);
        legals->setObjectName(QString::fromUtf8("legals"));
        legals->setGeometry(QRect(30, 80, 241, 51));
        legals->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(255, 255, 255)\n"
"}"));
        socials = new QLabel(widget);
        socials->setObjectName(QString::fromUtf8("socials"));
        socials->setGeometry(QRect(30, 160, 231, 16));
        socials->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(255, 255, 255)\n"
"}"));
        links = new QLabel(widget);
        links->setObjectName(QString::fromUtf8("links"));
        links->setGeometry(QRect(410, 30, 101, 21));
        QFont font7;
        font7.setUnderline(true);
        links->setFont(font7);
        links->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(255, 255, 255)\n"
"}"));
        topics = new QLabel(widget);
        topics->setObjectName(QString::fromUtf8("topics"));
        topics->setGeometry(QRect(340, 60, 231, 81));
        topics->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(255, 255, 255)\n"
"}"));
        ourstory = new QLabel(widget);
        ourstory->setObjectName(QString::fromUtf8("ourstory"));
        ourstory->setGeometry(QRect(420, 170, 101, 21));
        ourstory->setFont(font7);
        ourstory->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(255, 255, 255)\n"
"}"));
        story = new QLabel(widget);
        story->setObjectName(QString::fromUtf8("story"));
        story->setGeometry(QRect(360, 190, 211, 31));
        QFont font8;
        font8.setUnderline(false);
        story->setFont(font8);
        story->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(255, 255, 255)\n"
"}"));
        fb = new QLabel(widget);
        fb->setObjectName(QString::fromUtf8("fb"));
        fb->setGeometry(QRect(30, 200, 41, 41));
        fb->setPixmap(QPixmap(QString::fromUtf8(":/fb.png")));
        fb->setScaledContents(true);
        insta = new QLabel(widget);
        insta->setObjectName(QString::fromUtf8("insta"));
        insta->setGeometry(QRect(80, 200, 41, 41));
        insta->setPixmap(QPixmap(QString::fromUtf8(":/insta.jpeg")));
        insta->setScaledContents(true);
        pinoodle = new QLabel(widget);
        pinoodle->setObjectName(QString::fromUtf8("pinoodle"));
        pinoodle->setGeometry(QRect(130, 200, 41, 41));
        pinoodle->setPixmap(QPixmap(QString::fromUtf8(":/pinoodle.png")));
        pinoodle->setScaledContents(true);
        linkedin = new QLabel(widget);
        linkedin->setObjectName(QString::fromUtf8("linkedin"));
        linkedin->setGeometry(QRect(180, 200, 41, 41));
        linkedin->setPixmap(QPixmap(QString::fromUtf8(":/li.png")));
        linkedin->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 611, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "College Tour", nullptr));
        adminLogin->setText(QApplication::translate("MainWindow", "Admin", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Plan a \n"
"Trip", nullptr));
        display->setText(QApplication::translate("MainWindow", "College \n"
"Info", nullptr));
        bannerPhoto->setText(QString());
        find->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'URW Bookman'; font-size:50pt; font-weight:600; font-style:italic;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:48pt;\">Find </span></p></body></html>", nullptr));
        your->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'URW Bookman'; font-size:50pt; font-weight:600; font-style:italic;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:48pt;\">Your</span></p></body></html>", nullptr));
        future->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'URW Bookman'; font-size:50pt; font-weight:600; font-style:italic;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:48pt;\">Future</span></p></body></html>", nullptr));
        confetti->setText(QString());
        sponsor->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Proudly Sponsored by: </p></body></html>", nullptr));
        sorority->setText(QApplication::translate("MainWindow", "\342\210\206 \316\230 \316\273", nullptr));
        deltathetalambda->setText(QApplication::translate("MainWindow", "Delta Theta Lamda", nullptr));
        sororityValues->setText(QApplication::translate("MainWindow", "Honor  Service  Grace", nullptr));
        copyright->setText(QApplication::translate("MainWindow", "\302\2512022 OR 1=1 College Tours Inc. ", nullptr));
        legals->setText(QApplication::translate("MainWindow", "Legal Statement: OR 1=1 College \n"
"Tours Inc. is not affiliated with \n"
"any school or institution included.", nullptr));
        socials->setText(QApplication::translate("MainWindow", "Find us on our socials: ", nullptr));
        links->setText(QApplication::translate("MainWindow", "Quick Links: ", nullptr));
        topics->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Careers</p><p align=\"center\">Contact Us </p><p align=\"center\">Cancellation Policy</p></body></html>", nullptr));
        ourstory->setText(QApplication::translate("MainWindow", "Our Story: ", nullptr));
        story->setText(QApplication::translate("MainWindow", "talk about our startup here", nullptr));
        fb->setText(QString());
        insta->setText(QString());
        pinoodle->setText(QString());
        linkedin->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
