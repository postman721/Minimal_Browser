
//Minimal Browser is a C++ and QT5 browser.
//Copyright (c) 2020 JJ Posti <techtimejourney.net>
//This is free software, and you are welcome to redistribute it under GPL Version 2, June 1991″

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QString>
#include <QWebView>
#include <QtWidgets>
#include <QUrl>
#include <QtPrintSupport>
#include <QPrintDialog>
#include <QPrinter>
#include <QPageLayout>
#include <QWebInspector>
#include <QCoreApplication>
#include <QProcess>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//Basic file downloading.
    ui->webView->page()->setForwardUnsupportedContent(true);


    ui->webView->load(QUrl("https://d3q5u8uru3z1u9.cloudfront.net/postx/index.html"));

//Delegate links to new webview
    ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);


// Settings
    ui->webView->page()->settings()->setAttribute(QWebSettings::JavascriptEnabled,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::PluginsEnabled,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::PrivateBrowsingEnabled,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::SpatialNavigationEnabled,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::PrivateBrowsingEnabled,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::Accelerated2dCanvasEnabled,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::AutoLoadImages,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::ScrollAnimatorEnabled,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::FullScreenSupportEnabled,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::WebGLEnabled,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);

}

MainWindow::~MainWindow()
{
    delete ui;
}



// Saving with wget

void MainWindow::on_save_clicked() {
    QFileDialog dialog(this);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setAttribute(Qt::WA_DeleteOnClose);
    QString urls= ui->webView->url().toString();
    QString filename;
    filename = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                "",
                                                tr("All files (*"));

    QString getme=ui->webView->url().toString();


    QProcess proc;
    QStringList args;
    args << getme;
    args << "-O";
    args << filename;

   proc.start("wget", args);
        proc.waitForFinished();
        qDebug() << proc.readAllStandardOutput();

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
    x=ui->addressbar->text();

    QString y;
    y="https://";

    QString z;
    z="www.";

    if(ui->addressbar->text().startsWith(y)){ui->webView->load(QUrl(x));}
    if(ui->addressbar->text().startsWith(z)){ui->webView->load(QUrl(y+x));}

    }


void MainWindow::on_searchme_returnPressed()
{
    QString searching;
    searching=ui->searchme->text();
    QString engine="https://www.google.com/search?&q=" + searching;
    {ui->webView->load(QUrl(engine));};
}

void MainWindow::on_plus_clicked()
{
    ui->webView->setZoomFactor(ui->webView->zoomFactor()+.2);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->webView->setZoomFactor(ui->webView->zoomFactor()-.2);

}

