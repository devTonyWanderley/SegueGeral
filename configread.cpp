#include "configread.h"
#include "ui_configread.h"

ConfigRead::ConfigRead(QWidget *parent): QDialog(parent), ui(new Ui::ConfigRead)
{
    ui->setupUi(this);
    ui->pbCr1->setText("Ler arquivo");
    Range[0] = 0;
    Range[1] = 4;
    RgFlag = false;
    ui->pbCr4->setText("Ini");
}

bool ConfigRead::LerArquivo(QString dir, QString filtro, QString titulo)
{
    QString id = QFileDialog::getOpenFileName(this,titulo,dir,filtro);
    if(!id.length()) return false;
    QFile arq;
    arq.setFileName(id);
    if(!arq.open(QFile::ReadOnly | QFile::Text)) return false;
    Buffer = arq.readAll();
    arq.close();
    return true;
}

void ConfigRead::on_pbCr1_clicked()
{
    if(LerArquivo())
    {
        ui->pteCr1->setPlainText(Buffer);
        Linha = Buffer.left(Buffer.indexOf('\n'));
        ui->lbCr1->setText(Linha);
        Campo = Linha.right(Linha.length() - Range[0]);
        Campo = Campo.left(Range[1]);
        ui->lbCr2->setText(Campo);
    }
}

void ConfigRead::on_pbCr2_clicked()
{
    if(RgFlag)
    {
        if(Range[1] > 1) Range[1]--;
    }
    else
    {
        if(Range[0] > 0) Range[0]--;
    }
    Campo = Linha.right(Linha.length() - Range[0]);
    Campo = Campo.left(Range[1]);
    ui->lbCr2->setText(Campo);
}

void ConfigRead::on_pbCr3_clicked()
{
    if(RgFlag) Range[1]++;
    else
    {
        if(Range[0] < ui->lbCr1->text().length()) Range[0]++;
    }
    Campo = Linha.right(Linha.length() - Range[0]);
    Campo = Campo.left(Range[1]);
    ui->lbCr2->setText(Campo);
}

void ConfigRead::on_pbCr4_clicked()
{
    if(RgFlag)
    {
        ui->pbCr4->setText("Inic");
        RgFlag = false;
        return;
    }
    ui->pbCr4->setText("Fim");
    RgFlag = true;
}

ConfigRead::~ConfigRead()
{
    delete ui;
}
