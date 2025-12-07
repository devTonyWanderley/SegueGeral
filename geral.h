#ifndef GERAL_H
#define GERAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Geral;
}
QT_END_NAMESPACE

class Geral : public QMainWindow
{
    Q_OBJECT

public:
    Geral(QWidget *parent = nullptr);
    ~Geral();

private:
    Ui::Geral *ui;
};
#endif // GERAL_H
