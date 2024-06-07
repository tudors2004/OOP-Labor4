#ifndef LABORATOROOP_FRUIT_H
#define LABORATOROOP_FRUIT_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Medicine {
public:
	Medicine(const string& name, double quantity, double price, const string& category);

	string getName() const;
	double getPrice() const;
	double getQuantity() const;
	string getCategory() const;
	void setPrice(double price);

private:
	string name;
	double quantity;
	double price;
	string category;
};

#endif //LABORATOROOP_FRUIT_H
