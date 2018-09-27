#ifndef CAD_CARROS_H
#define CAD_CARROS_H

#include <QWidget>

namespace Ui {
class cad_carros;
}

class cad_carros : public QWidget
{
    Q_OBJECT

public:
    explicit cad_carros(QWidget *parent = nullptr);
    ~cad_carros();

private:
    Ui::cad_carros *ui;
};

#endif // CAD_CARROS_H
