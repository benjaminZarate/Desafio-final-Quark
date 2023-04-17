#pragma once
#include "Loan.h"
#include <vector>

using namespace std;

class LoanBook
{
public:
	void AddALoan(Loan* loan);
	void RemoveALoan(string bookName);
	vector<Loan*> returns;
	vector<Loan*> loans;
	int amountOfLoans = 0;
};