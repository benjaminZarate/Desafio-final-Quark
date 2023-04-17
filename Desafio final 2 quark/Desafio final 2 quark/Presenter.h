#pragma once
#include "View.h"
#include "PartnerRegular.h"
#include "PartnerVIP.h"
#include "LoanBook.h"
#include <string>

using namespace std;
class Presenter
{
public:
	Presenter();
	View* view;
	PartnerRegular* partnerRegular;
	PartnerVIP* partnerVIP;
	LoanBook loanBook;
	vector<Book*> books;
	void InitializeBooks();
	void MainMenu();
	void RegisterPartner();
	void BorrowBook();
	void LoanHistory();
	void ReturnsMade();
	void ReturnMainMenu();
	void InputCorrectUser(string &name);
	void ReturnABook();
};

