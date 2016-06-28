/**********************************************************
** Author: Jeffrey Schachtsick
** Date: 01/14/2015
** Description: This program will ask the user for the loan 
**     amount, monthly interest rate, and number of payments 
**     to be made.  Next, the program will calculate from 
**     those values to get the monthly payment, dollar amount 
**     in interest, and total loan amount plus interest.  
**     Then all user entries and results will be output to display.
***********************************************************/

#include <iostream>
#include <cmath>		// For the pow function
#include <iomanip>		// For the setprecision

using namespace std;

int main()
{
	// Variables
	double loan,			// Loan Amount
		monthlyPay,			// Monthly Payments
		convertInterest,	// Converted inteest from user integer value
		totalPayback,		// Total Loan plus Interest
		totalInterest,		// Interest in dollars
		powerInt;			// Interest to the power of payments

	int rateInterest,		// Monthly Interest Rate from User
		numPayments;		// Number of payments from User

	// Brief Program Introduction
	cout << "Welcome to the Loan Payments Program!" << endl;
	cout << "This program will ask a couple questions about the loan, and "
		<< "then calculate the monthly loan payments and total loan amount."
		<< endl;
	
	// Get loan amount, monthly int. rate, and num of payments from user
	cout << "What was the loan amount: ";
	cin >> loan;
	cout << "What was the monthly interest rate (e.g. type 4 for 4%): ";
	cin >> rateInterest;
	cout << "What is the number of monthly payments: ";
	cin >> numPayments;

	// Convert interest into decimal value
	convertInterest = rateInterest * 0.01;

	// Calculate the monthly payment, Interest in dollars, and total Loan amount
	// Calculate the Interest to the power of number of payments
	powerInt = pow((1 + convertInterest), numPayments);

	// Taking the interest to the power of payments calculate the monthly payment
	monthlyPay = ((convertInterest * powerInt) / (powerInt - 1)) * loan;

	// Calculate the interest in dollars
	totalInterest = (monthlyPay * numPayments) - loan;

	// Calculate the total loan amount
	totalPayback = totalInterest + loan;

	// Output select values to display
	cout << "\nLoan Amount:               $" << fixed << showpoint 
		<< setprecision(2) << loan;
	cout << "\nMonthly Interest Rate:     " << rateInterest << "%";
	cout << "\nNumber of Payments:        " << fixed << showpoint 
		<< setprecision(2) << numPayments;
	cout << "\nMonthly Payment:           $" << fixed << showpoint 
		<< setprecision(2) << monthlyPay;
	cout << "\nInterest in dollars:       $" << fixed << showpoint 
		<< setprecision(2) << totalInterest;
	cout << "\nTotal loan plus interest:  $" << fixed << showpoint 
		<< setprecision(2) << totalPayback;
     
     //Exit program
	return 0;
}