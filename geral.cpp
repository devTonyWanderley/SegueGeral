#include "geral.h"
#include "ui_geral.h"

Geral::Geral(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Geral)
{
    ui->setupUi(this);
    cr = new ConfigRead;
}

Geral::~Geral()
{
    delete ui;
}

void Geral::on_pbG1_clicked()
{
    cr->show();
}

