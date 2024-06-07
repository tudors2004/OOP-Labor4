#include "FruitRepo.h"

MedicineRepository& MedicineRepository::getInstance(){
	static MedicineRepository instance;
	return instance;
}

void MedicineRepository::addMedicine(const Medicine& medicine){
	medicines.push_back(medicine);
}

vector<Medicine> MedicineRepository::getAllMedicines() const{
	return medicines;
}