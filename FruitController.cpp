#include "FruitController.h"
#include "FruitRepo.h"

void MedicineController::addMedicine(const Medicine& medicine) {
	MedicineRepository::getInstance().addMedicine(medicine);
}

std::vector<Medicine> MedicineController::getTopCheapestProducts() {
	std::vector<Medicine> allMedicines = MedicineRepository::getInstance().getAllMedicines();
	std::vector<Medicine> topCheapest;
	for (const auto& medicine : allMedicines) {
		if (topCheapest.size() < 3) {
			topCheapest.push_back(medicine);
		} else {
			for (auto& topMedicine : topCheapest) {
				if (medicine.getPrice() < topMedicine.getPrice()) {
					topMedicine = medicine;
					break;
				}
			}
		}
		std::sort(topCheapest.begin(), topCheapest.end(), [](const Medicine& a, const Medicine& b) {
			return a.getPrice() < b.getPrice();
		});
	}

	return topCheapest;
}

std::vector<Medicine> MedicineController::getLastChanceCosmetics() {
	std::vector<Medicine> allMedicines = MedicineRepository::getInstance().getAllMedicines();
	std::vector<Medicine> lastChanceCosmetics;
	for (const auto& medicine : allMedicines) {
		if (medicine.getCategory() == "Cosmetics") {
			if (lastChanceCosmetics.size() < 2) {
				lastChanceCosmetics.push_back(medicine);
			}
		}
	}

	return lastChanceCosmetics;
}

