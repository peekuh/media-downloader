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
    QString program = R"(C:\\Users\\sarsr.LAPTOP-65K8MNNO\\scoop\\apps\\yt-dlp\\2023.03.04\\yt-dlp.exe)";
    QProcess process;
    process.start(program, args);
    process.waitForFinished(-1);

    QMessageBox::information(this, "Message", "Download complete.");
}

