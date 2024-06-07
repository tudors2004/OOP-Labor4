#include "Fruit.h"

Medicine::Medicine(const string& name, double quantity, double price, const string& category){
	this->name = name;
	this->quantity = quantity;
	this->price = price;
	this->category = category;

}

string Medicine::getName() const{
	return name;
}

double Medicine::getPrice() const{
	return price;
}

double Medicine::getQuantity() const {
	return quantity;
}

string Medicine::getCategory() const{
	return category;
}

void Medicine::setPrice(double price){
	this->price = price;
}