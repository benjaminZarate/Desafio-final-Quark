#pragma once
#include "CopyBook.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#ifndef COPYBOOK_H
#define COPYBOOK_H

using namespace std;

class Book
{
private:
	string ISBN;
	string author;
	string name;

public:
	Book(string ISBN, string name, string author, vector<CopyBook*> copybook);
	vector<CopyBook*> copybook;
	bool IsAvailable();
	CopyBook* BorrowBook(int index);
	void ReturnBook(int coybook);
	string GetName();
	string GetAuthor();
	string GetISBN();
};
#endif // !1