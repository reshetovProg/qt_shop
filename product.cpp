#include "product.h"

QString Product::getName() const
{
    return name;
}

void Product::setName(const QString &value)
{
    name = value;
}

QString Product::getCategory() const
{
    return category;
}

void Product::setCategory(const QString &value)
{
    category = value;
}

int Product::getPrice() const
{
    return price;
}

void Product::setPrice(int value)
{
    price = value;
}

Product::Product()
{
    Product::id++;
    uniqId=id;

}

int Product::id=0;
