#pragma once

#include <iostream>
using namespace std;
class CopyBook
{
private:
	int location;
public:
	CopyBook(int editionNumber, int location, int amountOfBooks);
	int editionNumber;
	int amountOfBooks;
	bool IsAvailable();
};

