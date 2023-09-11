#ifndef PRODUCT_H
#define PRODUCT_H
#include <QApplication>

class Product
{
private:
    static int id;
    int uniqId;
    QString name;
    QString category;
    int price;

public:
    Product();  
    QString getName() const;
    void setName(const QString &value);
    QString getCategory() const;
    void setCategory(const QString &value);
    int getPrice() const;
    void setPrice(int value);
};

#endif // PRODUCT_H
