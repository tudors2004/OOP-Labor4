#include "FruitRepo.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace Repository;
using namespace Domain;

FruitRepo::FruitRepo() {}

void FruitRepo::updateDeposit() {
	sort(fruitRepo.begin(), fruitRepo.end());
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
