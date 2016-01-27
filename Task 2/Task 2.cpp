#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>
using namespace std;

class SuperMarket
{
private:
	void SuperMarketAPI(); // API runs methods in proper(?) order
	void Greetings(); // Ask customer name, check time, greet customer (good morning, afternoon, evening)
	void Menu(); // Ask user to select from list of items which items were purchased and how many of each item
	void PrintInvoice();// Prints invoice from printInvoice to a file with the customer name as the file name (e.g. johnmeyer_receipt.txt)
	void ReadDatabase(); // Calculate and return the amount to be paid by the customer
	void PrintReceipt(); // Print a receipt with: Description, amount purchased, total on that item, and final total to be paid
	float Bill(); // Calculate and return the amount to be paid by the customer
	float totalBill; // The total bill paid
	char end;

	struct session {
		string customerName;
	} currentSession;

	struct item {
		string itemName;
		float itemPrice;
		int itemAmount;
	}items[5];

public:
	SuperMarket();
	~SuperMarket();
};

SuperMarket::SuperMarket() {
	SuperMarketAPI();
}

SuperMarket::~SuperMarket() {
	cout << "Deleted Object";
}

void SuperMarket::Greetings() {

	time_t TheTime; // declare a time object
	time(&TheTime); // Get the current time
	struct tm * timeinfo; // This will hold the time in an easy-to-use structure
	timeinfo = localtime(&TheTime); // This converts from raw time to the structure.

	cout << "Hello there, valued customer! May I get your name? " << endl;
	cin >> this->currentSession.customerName;
	if (timeinfo->tm_hour < 12) {
		cout << "Good morning, ";
	}
	else if (timeinfo->tm_hour < 17) {
		cout << "Good afternoon, ";
	}
	else {
		cout << "Good evening, ";
	}
	cout << this->currentSession.customerName << "!" << endl;
};

void SuperMarket::Menu() 
{
	cout << "Here is the menu for today: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Item: " << items[i].itemName << ", Price: " << items[i].itemPrice << endl;
		cout << "How many would you like? :" << endl;
		cin >> items[i].itemAmount;
	}
}

float SuperMarket::Bill() {
	float totalBill = 0;
	for (int i = 0; i < 5; i++) {
		totalBill = totalBill + items[i].itemPrice * items[i].itemAmount;
	}
	return totalBill;
}

void SuperMarket::PrintInvoice() 
{
	cout << "This is your invoice: " << endl;
	cout << "Customer: " << currentSession.customerName << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Item: " << items[i].itemName
			<< ", Quantity: " << items[i].itemAmount
			<< ", Cost: $" << items[i].itemAmount*items[i].itemPrice << endl;
	}
	cout << "Total: $" << SuperMarket::Bill() << endl;
}

void SuperMarket::ReadDatabase()
{
	ifstream inputStream;

	inputStream.open("item_list.txt");

	for (int i = 0; i < 5; i++) {
		size_t start = 0, end;
		string s, priceString;
		getline(inputStream, s);
		end = s.find_first_of("0123456789", start);
		items[i].itemName = s.substr(start, end - 1  - start);
		priceString = s.substr(end);
		items[i].itemPrice = stof(priceString);
		// cout << s << "--" << priceString << "--" << items[i].itemName << "--" << items[i].itemPrice << "-" << stof(priceString) << endl;
	}

	inputStream.close();
}

void SuperMarket::PrintReceipt()
{
	ofstream outputStream;
	outputStream.open("receipt.txt");

	outputStream << "Customer: " << currentSession.customerName << endl;
	for (int i = 0; i < 5; i++) {
		outputStream << "Item: " << items[i].itemName
			<< ", Quantity: " << items[i].itemAmount
			<< ", Cost: $" << items[i].itemAmount*items[i].itemPrice << endl;
	}
	outputStream << "Total: $" << SuperMarket::Bill() << endl ;
	outputStream.close();

}

void SuperMarket::SuperMarketAPI()
{
	ReadDatabase();
	Greetings();
	Menu();
	Bill();
	PrintInvoice();
	PrintReceipt();
	cout << "Press any key to close. ";
	char n = cin.get();
	cout << n;
}

int main()
{
	SuperMarket superMarket;
	return 0;
}