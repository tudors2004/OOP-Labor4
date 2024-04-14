#ifndef LABORATOROOP_FRUIT_H
#define LABORATOROOP_FRUIT_H
#include <iostream>
#include <vector>

using namespace std;
namespace Domain {
	class Fruit {
	private:
		string name;
		int price;
		string origin;
		string expirationDate;
		int quantity;

	public:

		Fruit(string name, string origin, string expirationDate, int price, int quantity);

		Fruit(string name, string origin);

		string getName() const;

		string getOrigin() const;

		string getExpirationDate() const;

		int getPrice() const;

		int getQuantity();

		void setName(string name);

		void setOrigin(string origin);

		void setExpirationDate(string expirationDate);

		void setPrice(int price);

		void setQuantity(int quantity);

		bool operator<(const Fruit &other) const {
			return name < other.name;
		}
		bool operator>(const Fruit &other) const {
			return name > other.name;
		}
	};
}
#endif //LABORATOROOP_FRUIT_H
