#ifndef LABORATOROOP_FRUITUI_H
#define LABORATOROOP_FRUITUI_H
#include "FruitController.h"
#include <string>
#include <iostream>
using namespace std;

class MedicineUI {
public:
	MedicineUI();
	void run();
	void displayAds(const string& label);
	void initialize();

private:
	MedicineController controller;

};


#endif //LABORATOROOP_FRUITUI_H
