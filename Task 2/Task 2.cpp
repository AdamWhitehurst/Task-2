// Paramters for bill?: int &firstItemAmount, int &secondItemAmount, int &thirdItemAmount, int &fourthItemAmount, int &fifthItemAmount

#include <iostream>
#include <fstream>
#include <time.h>


using namespace std;

class SuperMarket
{
private:
	void SuperMarketAPI(); // API runs methods in proper(?) order
	void Greetings(); // Ask customer name, check time, greet customer (good morning, afternoon, evening)
	void Menu(); // Ask user to select from list of 5 items which items were purchased and how many of each item
	void PrintInvoice();// Prints invoice from printInvoice to a file with the customer name as the file name (e.g. johnmeyer_receipt.txt)
	void ReadDatabase(); // Calculate and return the amount to be paid by the customer
	void PrintReceipt(); // Print a receipt with: Description, amount purchased, total on that item, and final total to be paid
	double Bill(); // Calculate and return the amount to be paid by the customer

	struct session {
		char customerName[20];
		int firstItemAmount, secondItemAmount, thirdItemAmount, fourthItemAmount, fifthItemAmount;
	} currentSession;

	struct item {
		string itemName;
		int itemPrice;
	}items[5];

public:
	SuperMarket() {
		SuperMarketAPI();
	}
};

void SuperMarket::Greetings() {

	time_t TheTime; // declare a time object
	time(&TheTime); // Get the current time
	struct tm * timeinfo; // This will hold the time in an easy-to-use structure
	timeinfo = localtime(&TheTime); // This converts from raw time to the structure.

	cout << "Hello there valued customer! May I get your name? ";
	cin.getline(this->currentSession.customerName, 20);
	if (timeinfo->tm_hour < 12) {
		cout << "Good morning ";
	}
	else if (timeinfo->tm_hour < 17) {
		cout << "Good afternoon ";
	}
	else {
		cout << "Good evening ";
	}
	cout << this->currentSession.customerName << "!" << endl;
};

void SuperMarket::Menu() 
{
	// TO-DO
}

double SuperMarket::Bill() {
	// TO-DO
}

void SuperMarket::PrintInvoice() 
{
	// TO-DO
	// I'm assuming he wants us to calculate the total price per each number of items (e.g. 2 apples for $5 total) here
	// and use result from bill method
}

void SuperMarket::ReadDatabase()
{
	// TO-DO
}

void SuperMarket::PrintReceipt()
{
	// TO-DO
}

void SuperMarket::SuperMarketAPI()
{
	ReadDatabase();
	Greetings();
	Menu();
	Bill();
	PrintInvoice();
	PrintReceipt();
}

int main()
{
	SuperMarket superMarket;

	return 0;
}