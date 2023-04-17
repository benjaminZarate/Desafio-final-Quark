#include "Partner.h"
#include "PartnerRegular.h"
#include "CopyBook.h"

PartnerRegular::PartnerRegular(string name, string lastname, int id)
{
	this->name = name;
	this->lastname = lastname;
	this->id = id;
}

bool PartnerRegular::CanBorrowABook()
{
	return book == NULL;
}

void PartnerRegular::BorrowBook(Book &newBook, int copybookIndex)
{
	if (!CanBorrowABook())
	{
		return;
	}
	book = &newBook;
	book->BorrowBook(copybookIndex);
}

void PartnerRegular::ReturnBook()
{
	book = NULL;
}