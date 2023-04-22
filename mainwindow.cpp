#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_download_button_clicked()
{
    //finding the QlineEdit object that holds the url entered by the user
    QLineEdit *lineEdit = this->findChild<QLineEdit*>("url_lineEdit");
    //getting the current text in the QlineEdit widget (url entered by user)
    QString url = lineEdit->text();
    QStringList args;
    args << url;

    QComboBox *combo = this->findChild<QComboBox*>("engine_combobox");
    QString combo_text = combo->currentText();
    QString str = "twitter";
    if (combo_text == str)
    {
        QString gallery_dl = R"(C:\Users\sarsr.LAPTOP-65K8MNNO\scoop\apps\gallery-dl\1.25.2\gallery-dl.exe)";
        QProcess twitter;
        twitter.start(gallery_dl, args);
        twitter.waitForFinished(-1);
        QMessageBox::information(this, "Message", "Download complete.");
    }
    else
    {
        QString program = R"(C:\\Users\\sarsr.LAPTOP-65K8MNNO\\scoop\\apps\\yt-dlp\\2023.03.04\\yt-dlp.exe)";
        QProcess process;
        process.start(program, args);
        process.waitForFinished(-1);

        QMessageBox::information(this, "Message", "Download complete.");
    }
}

