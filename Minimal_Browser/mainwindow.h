#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_back_clicked();

    void on_forward_clicked();

    void on_pushButton_clicked();

    void on_reload_clicked();

    void on_home_clicked();

    void on_addressbar_returnPressed();

    void on_Print_clicked();

    void on_webView_loadStarted();

    void on_webView_loadFinished(bool arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
