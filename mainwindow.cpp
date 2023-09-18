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

    ui->table->setColumnCount(4);
    QTableWidgetItem* item1 = new QTableWidgetItem("idProduct");
    QTableWidgetItem* item2 = new QTableWidgetItem("Product name");
    QTableWidgetItem* item3 = new QTableWidgetItem("Product category");
    QTableWidgetItem* item4 = new QTableWidgetItem("Product price");

    ui->table->setHorizontalHeaderItem(0,item1);
    ui->table->setHorizontalHeaderItem(1,item2);
    ui->table->setHorizontalHeaderItem(2,item3);
    ui->table->setHorizontalHeaderItem(3,item4);


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
        productsUniqName.insert(product.getName(), product.getUniqId());
    }
    categoriesName.insert(product.getCategory());
  /*  for (auto el : this-> productsUniqName.keys()){
         ui->otladka->setText(ui->otladka->text()+el+" ");
    }*/

    updateLists();
    updateTable();

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


}

void MainWindow::updateTable()
{
    ui->table->clear();
    ui->table->setRowCount(0);
    QTableWidgetItem* item1 = new QTableWidgetItem("Product name");
    QTableWidgetItem* item2 = new QTableWidgetItem("Product category");
    QTableWidgetItem* item3 = new QTableWidgetItem("Product price");
    QTableWidgetItem* item4 = new QTableWidgetItem("Product count");

    ui->table->setHorizontalHeaderItem(0,item1);
    ui->table->setHorizontalHeaderItem(1,item2);
    ui->table->setHorizontalHeaderItem(2,item3);
    ui->table->setHorizontalHeaderItem(3,item4);

    int a=0;
    for(auto el:this->productsName.keys()){

        QTableWidgetItem* count = new QTableWidgetItem(QString::number(productsName.value(el)));
        QTableWidgetItem* name = new QTableWidgetItem(products.value(productsUniqName.value(el)).getName());
        QTableWidgetItem* category = new QTableWidgetItem(products.value(productsUniqName.value(el)).getCategory());
        float price = products.value(productsUniqName.value(el)).getPrice();
        QTableWidgetItem* priceStr= new QTableWidgetItem(QString::number(price));


        ui->table->insertRow(a);

        ui->table->setItem(a,3, count);
        ui->table->setItem(a,0, name);
        ui->table->setItem(a,1, category);
        ui->table->setItem(a,2, priceStr);

        a++;

    }

}





void MainWindow::on_addProduct_category_currentTextChanged(const QString &arg1)
{

   ui->addProduct_name->clear();


   for (auto el : this->productsUniqName.keys()){
       if(products.value(productsUniqName.value(el)).getCategory()
               ==arg1)ui->addProduct_name->addItem(el);
   }
}

void MainWindow::on_removeProduct_category_currentTextChanged(const QString &arg1)
{
    ui->removeProduct_name->clear();


    for (auto el : this->productsUniqName.keys()){
        if(products.value(productsUniqName.value(el)).getCategory()
                ==arg1)ui->removeProduct_name->addItem(el);
    }

}

void MainWindow::on_filter_category_currentTextChanged(const QString &arg1)
{
    ui->filter_name->clear();


    for (auto el : this->productsUniqName.keys()){
        if(products.value(productsUniqName.value(el)).getCategory()
                ==arg1)ui->filter_name->addItem(el);
    }
}
