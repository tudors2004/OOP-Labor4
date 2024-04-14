#ifndef LABORATOROOP_FRUITCONTROLLER_H
#define LABORATOROOP_FRUITCONTROLLER_H
#include <memory>

#include "FruitRepo.h"
using namespace std;
using namespace Repository;
using namespace Domain;

namespace Controller {

	struct Date {
		int day, month, year;
	};

	class FruitController {
	private:
		shared_ptr<FruitRepo> repository;
	public:
		FruitController(shared_ptr<FruitRepo> repo);
		void addFruit(string name, string origin, string expirationDate, int price, int quantity);
		void deleteFruit(string name, string origin);
		vector<Fruit> findFruits(string str);
		vector<Fruit> showAll();
		vector<Fruit> stock(int quantity);
		vector<Date> getDates(const Fruit &f1, const Fruit &f2);
		bool compare(const Fruit &f1, const Fruit &f2);
		vector<Fruit> sortedExpirationDate();
	};
}
#endif //LABORATOROOP_FRUITCONTROLLER_H
