#pragma once
#include "Partner.h"
#include "Book.h"
#include<string>

using namespace std;

class PartnerRegular : public Partner
{
public:
	PartnerRegular(string name, string lastname, int id);
	Book *book;
	bool CanBorrowABook();
	void BorrowBook(Book &newBook, int copybookIndex);
	void ReturnBook();
};