#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    categoriesName.insert("овощи");
    categoriesName.insert("фрукты");
    categoriesName.insert("напитки");

    for (auto el: this->categoriesName){
        ui->addPosition_category->addItem(el);
        ui->addProduct_category->addItem(el);
        ui->removeProduct_category->addItem(el);
        ui->filter_category->addItem(el);
    }
    ui->addPosition_category->setEditable(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addPosition_btn_clicked()
{
    QString text = ui->addPosition_name->toPlainText();

}


