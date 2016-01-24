#include <iostream>
#include <fstream>
using namespace.std;

class SuperMarket
{
private:
	void greetings();
	void menu();
	void printInvoice();
	void readDatabase();
	void print_receipt();
	double bill();
	double applePrice = 2.99, breadLoafPrice = 3.95, juicePrice = 5.99, butterPrice = 6.99, eggPrice = 4.99;
public:
	SuperMarket();

};

int main()
{
	return 0;
}