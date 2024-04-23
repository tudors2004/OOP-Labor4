#include "FruitUI.h"
#include <string>
#include <iostream>
using namespace std;
using namespace UI;

FruitUI::FruitUI(shared_ptr<FruitController> contr) {
	controller = contr;
}
void FruitUI::menu() {
	int choice;
	bool running = true;
	string option;

	while (running) {
		cout<<endl;
		cout << "********** Welcome! **********\n";
		cout <<endl;
		cout << " 1 - Show inventory \n";
		cout << " 2 - Search for a specific item \n";
		cout << " 3 - Check stock \n";
		cout << " 4 - Check expiration dates \n";
		cout << " 5 - Add an item \n";
		cout << " 6 - Remove an item \n";
		cout << " 7 - Exit\n";
		cout << " Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				showAll();
				break;
			case 2:
				showFiltered();
				break;
			case 3:
				showAlmostEmpty();
				break;
			case 4:
				showExpirationDate();
				break;
			case 5:
				addFruit();
				break;
			case 6:
				deleteFruit();
				break;
			case 7:
				cout<<endl;
				cout << "Have a great day!"<< endl;
				running = false;
				break;
			default:
				cout << "Not a valid choice, please choose again. \n";
				cin >> choice;
				break;
		}
	}
}

void FruitUI::printVector(vector<Fruit> vector1) {
	for (int i = 0; i < vector1.size(); i++) {
		cout << endl;
		cout << "Name: " << vector1[i].getName() << "  Origin: " << vector1[i].getOrigin() << "  Expiration Date: "
		     << vector1[i].getExpirationDate() << "  Price: " << vector1[i].getPrice() << "  Quantity: "
		     << vector1[i].getQuantity();
		cout << endl;
	}
}

void FruitUI::showAll() {
	cout << endl;
	vector<Fruit> vector1 = controller->showAll();
	printVector(vector1);

}

void FruitUI::showAlmostEmpty() {
	cout << endl;
	cout << "Please enter a reference value: " << endl;
	int value;
	cin >> value;
	vector<Fruit> vector1 = controller->stock(value);
	printVector(vector1);
}

void FruitUI::showExpirationDate() {
	cout << endl;
	vector<Fruit> vector1 = controller->sortedExpirationDate();
	printVector(vector1);
}

void FruitUI::showFiltered() {
	cout << endl;
	string str;
	cout << "Please enter the search criteria: ";
	cin >> str;
	vector<Fruit> vector1 = controller->findFruits(str);
	printVector(vector1);
}

void FruitUI::addFruit() {
	cout << endl;
	string name, origin, expirationDate;
	int price, quantity;
	cout << "Name: ";
	cin >> name;
	cout <<endl;
	cout << "Origin: ";
	cin >> origin;
	cout <<endl;
	cout << "Expiration Date (Please use the following format: dd/mm/yyyy): ";
	cin >> expirationDate;
	cout <<endl;
	cout << "Price: ";
	cin >> price;
	cout <<endl;
	cout << "Quantity: ";
	cin >> quantity;
	cout <<endl;
	cout << "Adding item.." << endl;
	controller->addFruit(name, origin, expirationDate, price, quantity);
	cout << "Item added successfully!" << endl;

}

void FruitUI::deleteFruit() {
	cout << endl;
	string name, origin;
	cout << "Name: ";
	cin >> name;
	cout <<endl;
	cout << "Origin: ";
	cin >> origin;
	cout <<endl;
	cout <<endl;
	cout << "Removing item.." << endl;
	try {
		controller->deleteFruit(name, origin);
		cout << "Item removed successfully.." << endl;
	}
	catch (exception &e) {
		cout << "Item not found. Please try again!" << endl;
		deleteFruit();
	}
}

void FruitUI::initialize() {
	controller->addFruit("Mango", "Brazil", "22/10/2024", 1, 5);
	controller->addFruit("Banana", "Reunion", "01/01/2024", 2, 4);
	controller->addFruit("Apple", "Montenegro", "12/12/2024", 3, 3);
	controller->addFruit("Grape", "Laos", "31/01/2024", 4, 2);
	controller->addFruit("Plum", "USA", "30/02/2024", 5, 1);
}

