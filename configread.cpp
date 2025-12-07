#include "configread.h"
#include "ui_configread.h"

ConfigRead::ConfigRead(QWidget *parent): QDialog(parent), ui(new Ui::ConfigRead)
{
    ui->setupUi(this);
    ui->pbCr1->setText("Ler arquivo");
    Range[0] = 0;
    Range[1] = 4;
    RgFlag = false;
    Ranges.clear();
    LCampos.clear();
    NLinha = 0;
    ui->pbCr4->setText("Início");
    ui->pbCr5->setText("Insere");
    ui->lbCr1->setText("lbCr1");
    ui->lbCr2->setText("lbCr2");
    ui->lbCr3->setText("lbCr3");
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

void ConfigRead::AtuLinha()
{
    if(!NLinha)
    {
        Linha = Buffer.left(Buffer.indexOf('\n'));
        ui->lbCr1->setText(Linha);
        qDebug() << NLinha;
        return;
    }
    QString tx = Buffer;
    uint n = NLinha;
    while(n)
    {
        tx = tx.right(tx.length() - tx.indexOf('\n') - 1);
        n--;
    }
    qDebug() << NLinha;
    Linha = tx.left(tx.indexOf('\n'));
    ui->lbCr1->setText(Linha);
}

void ConfigRead::on_pbCr1_clicked()
{
    if(LerArquivo())
    {
        ui->pteCr1->setPlainText(Buffer);
        Linha = Buffer.left(Buffer.indexOf('\n'));
        AtuLinha();
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
    AtuLinha();
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
    AtuLinha();
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

void ConfigRead::on_pbCr5_clicked()
{
    Ranges.push_back(Range[0]);
    Ranges.push_back(Range[1]);
    LCampos.push_back(Campo);
    QString tx = "| ";
    for(uint i = 0; i < LCampos.length(); i++)
    {
        tx += LCampos.at(i);
        tx += " | ";
    }
    ui->lbCr3->setText(tx);
    for(uint i = 0; i < Ranges.length(); i++) qDebug() << Ranges.at(i);
    qDebug() << "----";
}

void ConfigRead::on_pbCr6_clicked()
{
    NLinha++;
    AtuLinha();
}

void ConfigRead::on_pvCr7_clicked()
{
    if(NLinha) NLinha--;
    AtuLinha();
}

ConfigRead::~ConfigRead()
{
    delete ui;
}
