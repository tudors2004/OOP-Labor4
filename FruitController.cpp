#include "FruitController.h"
#include <vector>
#include <sstream>
#include <algorithm>
using namespace Controller;
using namespace std;

FruitController::FruitController(shared_ptr<FruitRepo> repo) {
	repository = repo;
}

void FruitController::addFruit(string name, string origin, string expirationDate, int price, int quantity) {
	Fruit fruit(name, origin, expirationDate, price, quantity);
	repository->addFruit(fruit);
}

void FruitController::deleteFruit(string name, string origin) {
	Fruit fruit(name, origin);
	repository->deleteFruit(fruit);
}

vector<Fruit> FruitController::findFruits(string str) {
	vector<Fruit> fruits = repository->getAll();
	if (!str.empty()) {
		vector<Fruit> filtered;
		for (int i = 0; i < fruits.size(); i++) {
			string s1 = fruits[i].getName();
			string s2 = str;
			if (s1.find(s2) != -1) {
				filtered.push_back(fruits[i]);
			}
		}
		sort(filtered.begin(), filtered.end());
		return filtered;
	}
	sort(fruits.begin(), fruits.end());
	return fruits;

}

vector<Fruit> FruitController::showAll() {
	vector<Fruit> fruits = repository->getAll();
	sort(fruits.begin(), fruits.end());
	return fruits;
}


vector<Fruit> FruitController::stock(int quantity) {
	vector<Fruit> fruits = repository->getAll();
	vector<Fruit> stock;
	for (int i = 0; i < fruits.size(); ++i) {
		Fruit& fruit = fruits[i];
		if (fruit.getQuantity() <= quantity) {
			stock.push_back(fruit);
		}
	}
	return stock;
}

vector<Date> FruitController::getDates(const Fruit &f1, const Fruit &f2) {
	string expirationDate1 = f1.getExpirationDate();
	string expirationDate2 = f2.getExpirationDate();

	stringstream s1(expirationDate1);
	stringstream s2(expirationDate2);
	string day1, day2, month1, month2, year1, year2;
	getline(s1, day1, '/');
	getline(s2, day2, '/');
	getline(s1, month1, '/');
	getline(s2, month2, '/');
	getline(s1, year1);
	getline(s2, year2);

	int d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	stringstream(day1) >> d1;
	stringstream(day2) >> d2;
	stringstream(month1) >> m1;
	stringstream(month2) >> m2;
	stringstream(year1) >> y1;
	stringstream(year2) >> y2;

	Date date1 = {d1, m1, y1};
	Date date2 = {d2, m2, y2};

	return {date1, date2};
}

bool FruitController::compare(const Fruit &f1, const Fruit &f2) {
	vector<Date> dates = getDates(f1, f2);
	Date date1 = dates[0];
	Date date2 = dates[1];
	if (date1.year < date2.year)
		return true;
	if (date1.year > date2.year)
		return false;
	if (date1.year == date2.year) {
		if (date1.month < date2.month)
			return true;
		if (date1.month > date2.month)
			return false;
		if (date1.day == date2.day || date1.day < date2.day)
			return true;
		return false;
	}
}

vector<Fruit> FruitController::sortedExpirationDate() {
	vector<Fruit> fruits = repository->getAll();
	for (int i = 0; i < fruits.size(); i++) {
		for (int j = 0; j < fruits.size(); j++) {
			if (compare(fruits[i], fruits[j]))
				swap(fruits[i], fruits[j]);
		}
	}
	return fruits;
}
