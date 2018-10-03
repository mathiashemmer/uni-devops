#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    bool ValidatePassword(std::string user, std::string password);
    ~MainWindow();

private slots:
    void on_btn_Login_clicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
