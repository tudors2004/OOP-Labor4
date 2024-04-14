#ifndef LABORATOROOP_FRUITREPO_H
#define LABORATOROOP_FRUITREPO_H
#include "Fruit.h"
#include <memory>
using namespace Domain;

namespace Repository {
	class FruitRepo {
	private:
		vector<Fruit> fruitRepo;
	public:
		FruitRepo();
		void addFruit(Fruit fruit);
		void deleteFruit(Fruit fruit);
		void updateDeposit();
		vector<Fruit> getAll();
	};
}
#endif //LABORATOROOP_FRUITREPO_H
