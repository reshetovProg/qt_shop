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
    QString name = ui->addPosition_name->toPlainText();
    QString category = ui->addPosition_category->currentText();
    float price = ui->addPosition_price->toPlainText().toFloat();
    Product product(name, category, price);
    products.insert(product.getUniqId(), product);
    if(!productsName.contains(product.getName())){
        productsName.insert(product.getName(),0);
    }
    categoriesName.insert(product.getCategory());
    updateLists();

}

void MainWindow::updateLists()
{
     ui->addPosition_category->clear();
     ui->addProduct_category->clear();
     ui->removeProduct_category->clear();
     ui->filter_category->clear();
     ui->addProduct_name->clear();
     ui->removeProduct_name->clear();
     ui->filter_name->clear();



    for (auto el: this->categoriesName){
        ui->addPosition_category->addItem(el);
        ui->addProduct_category->addItem(el);
        ui->removeProduct_category->addItem(el);
        ui->filter_category->addItem(el);
    }


    for (auto el : this->productsName.keys()){
        ui->addProduct_name->addItem(el);
        ui->removeProduct_name->addItem(el);
        ui->filter_name->addItem(el);
    }


}


