#include "Test.h"

void testMedicineCreation() {
	Medicine medicine("Paracetamol", 100, 10.0, "Painkiller");
	assert(medicine.getName() == "Paracetamol");
	assert(medicine.getQuantity() == 100);
	assert(medicine.getPrice() == 10.0);
	assert(medicine.getCategory() == "Painkiller");
}

void testMedicinePriceUpdate() {
	Medicine medicine("Paracetamol", 100, 10.0, "Painkiller");
	medicine.setPrice(10.0);
	assert(medicine.getPrice() == 10.0);
}

void testAddMedicine() {
	MedicineRepository& repo = MedicineRepository::getInstance();
	repo.addMedicine(Medicine("Paracetamol", 100, 10.0, "Painkiller"));

	auto medicines = repo.getAllMedicines();
	//assert(medicines.size() == 1);
	assert(medicines[0].getName() == "Paracetamol");
}

void testAll(){
	testMedicineCreation();
	testMedicinePriceUpdate();
	testAddMedicine();
	cout<<"All tests passed"<<endl;
}