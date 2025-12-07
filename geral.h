/** @date   07/12/25    07:58
 */
#ifndef GERAL_H
#define GERAL_H

#include <QMainWindow>
#include "configread.h"

QT_BEGIN_NAMESPACE
namespace Ui {class Geral;}
QT_END_NAMESPACE

class Geral : public QMainWindow
{
    Q_OBJECT

public:
    Geral(QWidget *parent = nullptr);
    ~Geral();

private slots:
    void on_pbG1_clicked();

private:
    Ui::Geral *ui;
    ConfigRead *cr;
};
#endif // GERAL_H
