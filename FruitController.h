#ifndef LABORATOROOP_FRUITCONTROLLER_H
#define LABORATOROOP_FRUITCONTROLLER_H
#include <vector>
#include "FruitRepo.h"
#include <algorithm>
using namespace std;

class MedicineController {
public:
	void addMedicine(const Medicine& medicine);
	vector<Medicine> getTopCheapestProducts();
	vector<Medicine> getLastChanceCosmetics();

};
#endif //LABORATOROOP_FRUITCONTROLLER_H
