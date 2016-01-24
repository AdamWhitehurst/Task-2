// Paramters for bill?: int &firstItemAmount, int &secondItemAmount, int &thirdItemAmount, int &fourthItemAmount, int &fifthItemAmount

#include <iostream>
#include <fstream>
#include <string>
using namespace.std;

class SuperMarket
{
private:
	void greetings();
	void menu();
	void printInvoice();
	void readDatabase();
	void printReceipt();
	double bill();
	int firstItemAmount, secondItemAmount, thirdItemAmount, fourthItemAmount, fifthItemAmount;
	// string name; // I don't think I know how strings work

public:
	SuperMarket();

};

// Ask customer name, check time, greet customer (good morning, afternoon, evening)
void SuperMarket::greetings()
{
	// TO-DO
}

// Ask user to select from list of 5 items which items were purchased and how many of each item
void SuperMarket::menu() 
{
	// TO-DO
}

// Calculate and return the amount to be paid by the customer
double SuperMarket::bill() // Should we have parameters here?
{
	// TO-DO
}

// Print a receipt with: Description, amount purchased, total on that item, and final total to be paid
void SuperMarket::printInvoice() 
{
	// TO-DO
	// I'm assuming he wants us to calculate the total price per each number of items (e.g. 2 apples for $5 total) here
	// and use result from bill method
}

// Read the file that contains Item name and price (each on one line)
void readDatabase()
{
	// TO-DO
}

// Prints invoice from printInvoice to a file with the customer name as the file name (e.g. johnmeyer_receipt.txt)
void printReceipt()
{
	// TO-DO
}

// Constructor runs methods in proper(?) order
SuperMarket::SuperMarket()
{
	readDatabase();
	greetings();
	menu();
	bill();
	printInvoice();
	printReceipt();
}

int main()
{
	// SuperMarket mySuperMarket;
	return 0;
}