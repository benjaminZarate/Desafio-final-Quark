#include "Partner.h"
#include "PartnerVIP.h"
#include "Book.h"

PartnerVIP::PartnerVIP(string name, string lastname, int id)
{
	this->name = name;
	this->lastname = lastname;
	this->id = id;
}

bool PartnerVIP::CanBorrowABook()
{
	return currentAmountOfBooks < 3;
}

void PartnerVIP::BorrowBook(Book &newBook, int copybookIndex)
{
	if (!CanBorrowABook())
	{
		return;
	}
	if (currentAmountOfBooks < 3)
	{
		books.push_back(&newBook);
		newBook.BorrowBook(copybookIndex);
		currentAmountOfBooks++;
	}
}

void PartnerVIP::ReturnBook(int index) 
{
	auto remove = next(books.begin(), index);
	books.erase(remove);
}