
//Minimal Browser is a C++ and QT5 browser.
//Copyright (c) 2020 JJ Posti <techtimejourney.net>
//This is free software, and you are welcome to redistribute it under GPL Version 2, June 1991″

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebView>
#include <QtWidgets>
#include <QUrl>
#include <QString>
#include <QtPrintSupport>
#include <QPrintDialog>
#include <QPrinter>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPageLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webView->load(QUrl("https://d3q5u8uru3z1u9.cloudfront.net/postx/index.html"));

//Delegate links to new webview
    ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_back_clicked()
{
    ui->webView->back();
    ui->addressbar->setText(ui->webView->url().toString());

}

void MainWindow::on_forward_clicked()
{
    ui->webView->forward();
    ui->addressbar->setText(ui->webView->url().toString());

}

void MainWindow::on_pushButton_clicked()
{
    ui->webView->stop();
    ui->statusBar->showMessage("Loading stopped");
}

void MainWindow::on_reload_clicked()
{
    ui->webView->reload();
    ui->addressbar->setText(ui->webView->url().toString());

}

void MainWindow::on_home_clicked()
{
    ui->webView->load(QUrl("https://d3q5u8uru3z1u9.cloudfront.net/postx/index.html"));


}

void MainWindow::on_Print_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    if(dialog.exec() != QDialog::Accepted) return;
    ui->webView->print(&printer);
}

void MainWindow::on_webView_loadStarted()
{
    ui->statusBar->showMessage("Loading URL (https)" );
}

void MainWindow::on_webView_loadFinished(bool arg1)
{

if (arg1){
    ui->statusBar->showMessage("Loading finished (https)");
    ui->addressbar->setText(ui->webView->url().toString());}
else {ui->statusBar->showMessage("Loading has failed.");}
}


void MainWindow::on_addressbar_returnPressed()
{
    QString x;
    QString y;
    y="https://";
    x=ui->addressbar->text();
    {ui->webView->load(QUrl(y+x));};
}
