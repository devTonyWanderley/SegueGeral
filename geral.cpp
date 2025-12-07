#include "geral.h"
#include "ui_geral.h"

Geral::Geral(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Geral)
{
    ui->setupUi(this);
}

Geral::~Geral()
{
    delete ui;
}
