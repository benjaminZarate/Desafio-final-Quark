#include "Book.h"
#include "CopyBook.h"
#include <string>

using namespace std;

Book::Book(string ISBN, string name, string author, vector<CopyBook*> copybook)
{
    this->ISBN = ISBN;
    this->author = author;
    this->name = name;
    this->copybook = copybook;
}

bool Book::IsAvailable()
{
    return copybook.size() > 0;
}

CopyBook* Book::BorrowBook(int index)
{
    try
    {
        if (copybook[index]->IsAvailable()) { return nullptr; }
        CopyBook* newBook = copybook[index];
        copybook[index]->amountOfBooks--;
        return newBook;
    }
    catch (exception e)
    {
        return nullptr;
    }
}

void Book::ReturnBook(int newbook)
{
    copybook[newbook]->amountOfBooks++;
}

string Book::GetName() 
{
    return name;
}

string Book::GetAuthor() 
{
    return author;
}

string Book::GetISBN() 
{
    return ISBN;
}