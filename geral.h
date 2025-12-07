/** @date   07/12/25    07:58
 *  @brief  Capacidade pra decodificar arquivos texto,
 *          a princípio, de comprimento fixo.
 *          A segunda etapa será mesclar com identificação
 *          de bandeiras no corpo do texto que separam dados,
 *          e posteriormente, duas estruturas de dados
 *          diferentes, chegando aí à leitura de arquivo do
 *          tipo caderneta gd5 onde temos estações e visadas.
 *          Ópta por fazê-lo parametrizado, de forma que se
 *          possa usar o presente pra outras situações similares.
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
