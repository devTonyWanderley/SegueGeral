#ifndef CONFIGREAD_H
#define CONFIGREAD_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>

#define DEFDIR "C:\\2025\\Soft\\InstLocal\\"

namespace Ui {class ConfigRead;}

class ConfigRead : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigRead(QWidget *parent = nullptr);
    ~ConfigRead();

private slots:
    void on_pbCr1_clicked();

    void on_pbCr2_clicked();

    void on_pbCr4_clicked();

    void on_pbCr3_clicked();

private:
    Ui::ConfigRead *ui;
    QString Buffer;
    QString Linha;
    QString Campo;
    QStringList LCampos;
    QList<uint> Ranges;
    uint Range[2];
    bool RgFlag;

    bool LerArquivo(QString dir = DEFDIR, QString filtro = "Todos (*.*)", QString titulo = "Abrir arquivo bruto");
};

#endif // CONFIGREAD_H
