#include "FruitRepo.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace Repository;
using namespace Domain;

FruitRepo::FruitRepo() {
	ifstream file("Deposit");
	if (!file.is_open()) {
		return;
	}
	string line;
	while (getline(file, line)) {
		stringstream ss(line);
		string name, origin, expirationDate, pricestr, quantitystr;
		getline(ss, name, ',');
		getline(ss, origin, ',');
		getline(ss, expirationDate, ',');
		getline(ss, pricestr, ',');
		getline(ss, quantitystr, ',');
		int price = 0, quantity = 0;
		stringstream(pricestr) >> price;
		stringstream(quantitystr) >> quantity;
		Fruit fruit(name, origin, expirationDate, price, quantity);
		fruitRepo.push_back(fruit);
	}
	file.close();
}

void FruitRepo::updateDeposit() {
	sort(fruitRepo.begin(), fruitRepo.end());
	ofstream file;
	file.open("Deposit");
	for (int i = 0; i < fruitRepo.size(); i++) {
		file << fruitRepo[i].getName() << ',';
		file << fruitRepo[i].getOrigin() << ',';
		file << fruitRepo[i].getExpirationDate() << ',';
		file << fruitRepo[i].getPrice() << ',';
		file << fruitRepo[i].getQuantity() << endl;
	}
}

void FruitRepo::addFruit(Fruit fruit) {
	bool found = false;
	for (int i = 0; i < fruitRepo.size(); i++)
		if (fruitRepo[i].getName() == fruit.getName() && fruitRepo[i].getOrigin() == fruit.getOrigin()) {
			found = true;
			int oldQuantity = fruitRepo[i].getQuantity();
			int newQuantity = oldQuantity + fruit.getQuantity();
			fruitRepo[i].setQuantity(newQuantity);
			break;

		}
	if (!found)
		this->fruitRepo.push_back(fruit);
	updateDeposit();

}

void FruitRepo::deleteFruit(Fruit fruit) {
	bool found = false;
	for (int i = 0; i < fruitRepo.size(); i++)
		if (fruitRepo[i].getName() == fruit.getName() && fruitRepo[i].getOrigin() == fruit.getOrigin()) {
			fruitRepo.erase(fruitRepo.begin() + i);
			found = true;
			break;
		}
	if (found)
		updateDeposit();
	else {
		throw invalid_argument("Item not found!");
	}

}

vector<Fruit> FruitRepo::getAll() {
	return fruitRepo;
}
