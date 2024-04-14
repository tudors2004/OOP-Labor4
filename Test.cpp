#include "Test.h"
#include <cassert>

using namespace Test;

Tests::Tests(shared_ptr<FruitController> contr) {
	controller = contr;
}

void Tests::testAdd() {
	cout << endl;
	cout << "Test add";
	string name = "Ceva", origin = "Ceva", expirationDate = "zz/zz/zzzz";
	int price = 10, quantity = 40;
	controller->addFruit(name, origin, expirationDate, price, quantity);
	vector<Fruit> vector1 = controller->showAll();
	bool found = false;
	for(int i = 0;i<vector1.size();i++)
		if(vector1[i].getName()==name&&vector1[i].getOrigin()==origin)
			found = true;
	assert(found == true);
}


void Tests::testRemove() {
	cout << endl;
	cout << "Test remove"<<endl;
	string name = "Ceva", origin = "Ceva";
	controller->deleteFruit(name, origin);
	vector<Fruit> vector1 = controller->showAll();
	bool found = false;
	for(int i = 0;i<vector1.size();i++)
		if(vector1[i].getName()==name&&vector1[i].getOrigin()==origin)
			found = true;
	assert(found == false);

}
void Tests::testFiltered() {
	cout << endl;
	cout << "Test filtered search" << endl;
	cout << endl;
	string str = "Ba";
	vector<Fruit> vector1 = controller->findFruits(str);
	if (!vector1.empty()) {
		assert(!vector1.empty());
		assert(vector1[vector1.size() - 1].getName() == "Banana");
	}
}

void Tests::testTrackStock() {
	cout << "Test track stock"<<endl;
	int value = 19;
	vector<Fruit> vector1 = controller->stock(value);
	assert(vector1.empty());
}

void Tests::testExpirationDate() {
	cout << "Test expiration date"<<endl;
	vector<Fruit> vector1 = controller->sortedExpirationDate();
	assert(vector1[0].getName() == "Mango");
}
void Tests::testAll() {
	cout<<endl;
	testAdd();
	testRemove();
	testTrackStock();
	testExpirationDate();
	testFiltered();
}