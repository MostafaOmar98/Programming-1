/*
 * Author: Mostafa Omar Mahmoud El-Sayed
 * ID: 20170292
 * Date: 23/2/2018
 * Teaching Assistant: Eng. Ibrahim Zidan
 * Problem 7 Page 107 in the C++ book
 * Program that calculates the new price of an item after a specified time due to some rate of inflation. User should enter the current cost, number of years
 * from now that the item will be purchased, and rate of inflation.
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << "Hello user\nEnter the cost of the item: ";
	float cost;
	cin >> cost;
	cout << "\nNow please enter the number of years from now that the item will be purchased: ";
	int nYears;
	cin >> nYears;
	cout << "\nNow please enter the rate of inflation percentage per year (%): ";
	float rate;
	cin >> rate;
	rate /= 100;
	float new_cost = cost;
	while (nYears--)
	{
		new_cost += new_cost*rate;
	}
	cout << "The new cost of the item is: " << setprecision(2) << fixed <<new_cost << endl;
	return 0;
}
