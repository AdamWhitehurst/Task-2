#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

class SuperMarket
{
private:
	void Greetings(); // Takes user input for the customer name then greets the customer according to the current system time
	void Menu();
	void PrintInvoice();
	void ReadDatabase();
	void PrintReceipt();
	char customerName[20];
	double Bill();
	double  applePrice = 2.99;
	double  breadLoafPrice = 3.95;
	double  juicePrice = 5.99;
	double  butterPrice = 6.99;
	double  eggPrice = 4.99;
public:
	SuperMarket() {
		Greetings();
	}
};

void SuperMarket::Greetings() {

	time_t TheTime; // declare a time object
	time(&TheTime); // Get the current time
	struct tm * timeinfo; // This will hold the time in an easy-to-use structure
	timeinfo = localtime(&TheTime); // This converts from raw time to the structure.

	cout << "Hello there valued customer! May I get your name? ";
	cin.getline(this->customerName, 20);
	if (timeinfo->tm_hour < 12) {
		cout << "Good morning ";
	}
	else if (timeinfo->tm_hour < 17) {
		cout << "Good afternoon ";
	}
	else {
		cout << "Good evening ";
	}
	cout << this->customerName << "!" << endl;
};

int main(void)
{
	SuperMarket superMarket;

	return 0;
}