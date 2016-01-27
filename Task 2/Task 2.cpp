#include <iostream>
#include <string>
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
		inputStream >> items[i].itemName >> items[i].itemPrice;
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
	/*items[0] = { "Apple", 1.00 };
	items[1] = { "Salad Mix", 1.50 };
	items[2] = { "Pork", 5.00 };
	items[3] = { "Tomato", 1.00 };
	items[4] = { "Spicy Southwest Chipotle Salad Dressing", 2.00 };*/
	ReadDatabase();
	Greetings();
	Menu();
	Bill();
	PrintInvoice();
	PrintReceipt();
	cout << "Enter any character to close: ";
	cin >> end;
}

int main()
{
	SuperMarket superMarket;

	return 0;
}