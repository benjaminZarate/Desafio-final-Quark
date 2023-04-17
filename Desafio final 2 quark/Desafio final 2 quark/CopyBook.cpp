#include "CopyBook.h"

CopyBook::CopyBook(int editionNumber, int location, int amountOfBooks) 
{
	this->editionNumber = editionNumber;
	this->location = location;
	this->amountOfBooks = amountOfBooks;
}

bool CopyBook::IsAvailable() 
{
	return amountOfBooks > 0;
}