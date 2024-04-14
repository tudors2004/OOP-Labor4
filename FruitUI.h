#ifndef LABORATOROOP_FRUITUI_H
#define LABORATOROOP_FRUITUI_H
#include "FruitController.h"
using namespace Controller;

namespace UI {
	class FruitUI {
	private:
		shared_ptr<FruitController> controller;
	public:
		FruitUI(shared_ptr<FruitController> contr);
		void menu();
		void printVector(vector<Fruit> vector1);
		void showAll();
		void showFiltered();
		void showAlmostEmpty();
		void showExpirationDate();
		void addFruit();
		void deleteFruit();
	};
}

#endif //LABORATOROOP_FRUITUI_H
