#pragma once
#include "Partner.h"
#include "Book.h"
#include <string>

using namespace std;

class PartnerVIP : public Partner
{
private:
	int suscriptionFee;
	int currentAmountOfBooks;
public:
	PartnerVIP(string name, string lastname, int id);
	bool CanBorrowABook();
	vector<Book*> books;
	void BorrowBook(Book &newBook, int copybookIndex);
	void ReturnBook(int index);
};
