#ifndef LABORATOROOP_TEST_H
#define LABORATOROOP_TEST_H
#include <iostream>
#include <memory>
#include "FruitRepo.h"
#include "FruitController.h"
using namespace std;
using namespace Controller;

namespace Test {
	class Tests {
	private:
		shared_ptr<FruitController> controller;
	public:
		Tests(shared_ptr<FruitController> contr);
		void testAdd();
		void testRemove();
	};
}


#endif //LABORATOROOP_TEST_H
