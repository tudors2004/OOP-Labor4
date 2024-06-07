#include "FruitUI.h"
MedicineUI::MedicineUI() {}

void MedicineUI::initialize() {
	controller.addMedicine(Medicine("Paracetamol", 150, 10.0, "Headache"));
	controller.addMedicine(Medicine("Clear", 120, 10.0, "Shampoo"));
	controller.addMedicine(Medicine("Ibuprofen", 100, 10.0, "Painkiller"));
	controller.addMedicine(Medicine("Nivea", 130, 12.0, "Gel"));
}

void MedicineUI::run() {
	initialize();

	int option;
	cout << "What option do you choose? (1 sau 2): ";
	cin >> option;

	string label;

	if (option == 1) {
		label = "top-cheapest-products";
	} else if (option == 2) {
		label = "last-chance-cosmetics";
	} else {
		cout << "Optiune invalida. Se va afisa top-cheapest-products.\n";
		label = "top-cheapest-products";
	}

	displayAds(label);
}

void MedicineUI::displayAds(const std::string& label) {
	if (label == "top-cheapest-products") {
		auto products = controller.getTopCheapestProducts();
		cout << "Top 3 cheapest products:\n";
		for (const auto& product : products) {
			cout << "Name: " << product.getName()
			          << ", Price: " << product.getPrice() << "\n";
		}
	} else if (label == "last-chance-cosmetics") {
		auto products = controller.getLastChanceCosmetics();
		cout << "Last Chance Cosmetics:\n";
		for (const auto& product : products) {
			cout << "Name: " << product.getName()
			          << ", Quantity: " << product.getQuantity() << "\n";
		}
	} else {
		cout << "Label unknown.\n";
	}
}
