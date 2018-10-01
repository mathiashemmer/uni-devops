#ifndef MODULESCREEN_H
#define MODULESCREEN_H

#include <QDialog>

namespace Ui {
class ModuleScreen;
}

class ModuleScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ModuleScreen(QWidget *parent = nullptr);
    ~ModuleScreen();

private slots:
    void on_pbtn_Veiculos_clicked();

    void on_tab_Veiculos_tabBarClicked(int index);

    void on_tab_Veiculos_tabBarDoubleClicked(int index);

    void on_tabWidget_tabBarDoubleClicked(int index);

private:
    Ui::ModuleScreen *ui;
};

#endif // MODULESCREEN_H
