#pragma once
#include "Partner.h"
#include "Book.h"
#include "CopyBook.h"

class Loan
{
public:
	Loan(Book *copyBook, Partner *partner); //El constructor genera la fecha
	Book *copyBook;
	Partner *partner;
	std::string date = "";
};

