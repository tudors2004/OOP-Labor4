#ifndef LABORATOROOP_FRUITREPO_H
#define LABORATOROOP_FRUITREPO_H
#include "Fruit.h"
#include <memory>
#include <vector>
using namespace std;

class MedicineRepository {
public:
	static MedicineRepository& getInstance();
	void addMedicine(const Medicine& medicine);
	vector<Medicine> getAllMedicines() const;

private:
	MedicineRepository() {}
	MedicineRepository(const MedicineRepository&) = delete;
	vector<Medicine> medicines;
	//MedicineRepository& operator=(const MedicineRepository&) = delete;
};

#endif //LABORATOROOP_FRUITREPO_H
