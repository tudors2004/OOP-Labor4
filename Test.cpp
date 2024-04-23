#include "Test.h"
#include <cassert>
using namespace Test;

Tests::Tests(shared_ptr<FruitController> contr) {
	controller = contr;
}

void Tests::testAdd() {
	cout << endl;
	string name = "Ceva", origin = "Ceva", expirationDate = "zz/zz/zzzz";
	int price = 10, quantity = 40;
	controller->addFruit(name, origin, expirationDate, price, quantity);
	vector<Fruit> vector1 = controller->showAll();
	bool found = false;
	for(int i = 0;i<vector1.size();i++)
		if(vector1[i].getName()==name&&vector1[i].getOrigin()==origin)
			found = true;
	assert(found == true);
	cout << "Test add passed!";
}

void Tests::testRemove() {
	cout << endl;
	string name = "Ceva", origin = "Ceva";
	controller->deleteFruit(name, origin);
	vector<Fruit> vector1 = controller->showAll();
	bool found = false;
	for(int i = 0;i<vector1.size();i++)
		if(vector1[i].getName()==name&&vector1[i].getOrigin()==origin)
			found = true;
	assert(found == false);
	cout << "Test remove passed!"<<endl;
}
