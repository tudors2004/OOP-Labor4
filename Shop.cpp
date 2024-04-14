#include "FruitUI.h"
#include "Test.h"
#include <memory>
using namespace UI;
using namespace Test;
using namespace std;

int main() {
	shared_ptr<FruitRepo> repo = make_shared<FruitRepo>();
	shared_ptr<FruitController> controller = make_shared<FruitController>(repo);
	FruitUI ui(controller);
	ui.menu();
	Tests test(controller);
	test.testAll();
	return 0;
}
