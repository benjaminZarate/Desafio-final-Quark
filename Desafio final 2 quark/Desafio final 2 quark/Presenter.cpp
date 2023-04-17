#include "Presenter.h"
#include <string>

using namespace std;

Presenter::Presenter()
{
	view = new View();
	InitializeBooks();
}

void Presenter::InitializeBooks() 
{
	CopyBook* copybook1 = new CopyBook(1, 0, 3);
	CopyBook* copybook2 = new CopyBook(2, 1, 2);
	CopyBook* copybook3 = new CopyBook(3, 2, 1);
	CopyBook* copybook4 = new CopyBook(4, 3, 10);
	CopyBook* copybook5 = new CopyBook(5, 4, 10);
	vector<CopyBook*> copybooks1 = { copybook1, copybook2 };
	vector<CopyBook*> copybooks2 = { copybook3, copybook4, copybook5 };

	Book* book1 = new Book("0000", "El principito", "Antoine de Saint-Exupéry", copybooks1);
	Book* book2 = new Book("0001", "Orgullo y prejuicio", "Jane Austen", copybooks2);

	books.push_back(book1);
	books.push_back(book2);
}

void Presenter::MainMenu()
{
	int input = 0;

	view->MainMenu();
	view->RegisterInput(input);
	try 
	{
		if (input == 1)
		{
			RegisterPartner();
		}
		else if (input == 2) 
		{
			BorrowBook();
		}
		else if (input == 3) 
		{
			LoanHistory();
		}
		else if (input == 4) 
		{
			ReturnsMade();
		}
		else if (input == 5) 
		{
			ReturnABook();
		}
		else 
		{
			view->EnterMessage("Invalid input");
			ReturnMainMenu();
		}
	}
	catch (exception e) 
	{
		view->EnterMessage("Invalid input");
		ReturnMainMenu();
	}
}

void Presenter::RegisterPartner() 
{
	int isVIP = 0;
	string partnerName = " ";
	string partnerLastname = " ";
	view->AskForName();
	view->RegisterInput(partnerName);
	view->AskForLastname();
	view->RegisterInput(partnerLastname);
	view->AskIfWantToBeVIP();
	view->RegisterInput(isVIP);

	try
	{
		if (isVIP == 1)
		{
			partnerVIP = new PartnerVIP(partnerName, partnerLastname, 0);
		}
		else if (isVIP == 2)
		{
			partnerRegular = new PartnerRegular(partnerName, partnerLastname, 0);
		}
	}
	catch (exception e)
	{
		view->EnterMessage("Invalid input");
		ReturnMainMenu();
	}
	MainMenu();
}

void Presenter::BorrowBook() 
{
	if (partnerRegular == NULL && partnerVIP == NULL)
	{
		int input = 0;
		view->EnterMessage("First register a partner");
		ReturnMainMenu();
	}
	else
	{
		int bookSelection = 0;
		int copybookSelection = 0;
		string name = " ";
		view->AskForBook();
		for (size_t i = 0; i < books.size(); i++)
		{
			string bookData = to_string(i) + ") " + books[i]->GetName() + " by " + books[i]->GetAuthor();
			view->EnterMessage(bookData);
		}
		view->RegisterInput(bookSelection);

		Book* newBook = books[bookSelection];
		view->AskForCopybook(newBook->GetName());
		for (size_t i = 0; i < newBook->copybook.size(); i++)
		{
			string data = to_string(i) + ") " + newBook->GetName() + " edition " + to_string(newBook->copybook[i]->editionNumber) + "\n";
			view->EnterMessage(data);
		}
		view->RegisterInput(copybookSelection);

		while (!newBook->copybook[copybookSelection]->IsAvailable()) 
		{
			view->AskForCopybook(newBook->GetName());
			for (size_t i = 0; i < newBook->copybook.size(); i++)
			{
				string data = to_string(i) + ") " + newBook->GetName() + " edition " + to_string(newBook->copybook[i]->editionNumber) + "\n";
				view->EnterMessage(data);
			}
			view->RegisterInput(copybookSelection);
		}
		InputCorrectUser(name);
		if (partnerVIP != NULL && name == partnerVIP->GetName())
		{
			while (name != partnerVIP->GetName())
			{
				InputCorrectUser(name);
			}
			if (!partnerVIP->CanBorrowABook())
			{
				ReturnMainMenu();
				return;
			}
			partnerVIP->BorrowBook(*newBook, copybookSelection);
			Loan* newLoan = new Loan(newBook, partnerVIP);
			loanBook.AddALoan(newLoan);
		}
		if(partnerRegular != NULL && name == partnerRegular->GetName())
		{
			while (name != partnerRegular->GetName())
			{
				InputCorrectUser(name);
			}
			if (!partnerRegular->CanBorrowABook()) 
			{
				ReturnMainMenu();
				return;
			}
			partnerRegular->BorrowBook(*newBook, copybookSelection);
			Loan* newLoan = new Loan(newBook, partnerRegular);
			loanBook.AddALoan(newLoan);
		}
		MainMenu();
	}
}

void Presenter::LoanHistory() 
{
	int input = 0;
	view->LoanHistoryTitle();
	for (size_t i = 0; i < loanBook.loans.size(); i++)
	{
		view->EnterMessage("Date: " + loanBook.loans[i]->date);
		view->EnterMessage("Book borrowed: " + loanBook.loans[i]->copyBook->GetName() + " by " + loanBook.loans[i]->copyBook->GetAuthor());
		view->EnterMessage("Partner: " + loanBook.loans[i]->partner->GetFullName());
	}
	ReturnMainMenu();
}

void Presenter::ReturnABook() 
{
	if (partnerRegular == NULL && partnerVIP == NULL)
	{
		int input = 0;
		view->EnterMessage("First register a partner");
		ReturnMainMenu();
	}

	if (partnerVIP != NULL) 
	{
		if (partnerVIP->books.size() <= 0) 
		{
			ReturnMainMenu();
		}
		int input = 0;
		view->EnterMessage("Which book you want to return");
		for (size_t i = 0; i < partnerVIP->books.size(); i++)
		{
			view->EnterMessage(to_string(i) + ") " + partnerVIP->books[i]->GetName());
		}
		view->RegisterInput(input);
		view->EnterMessage(partnerVIP->books[input]->GetName() + "returned");
		loanBook.RemoveALoan(partnerVIP->books[input]->GetName());
		partnerVIP->ReturnBook(input);
	}
	if(partnerRegular != NULL)
	{
		if (partnerRegular->book == NULL) 
		{
			ReturnMainMenu();
		}
		view->EnterMessage(partnerRegular->book->GetName() + " returned");
		loanBook.RemoveALoan(partnerRegular->book->GetName());
		partnerRegular->ReturnBook();
	}
	ReturnMainMenu();
}

void Presenter::ReturnsMade() 
{
	for (size_t i = 0; i < loanBook.returns.size(); i++)
	{
		view->EnterMessage(loanBook.returns[i]->copyBook->GetName() + " returned");
	}
	ReturnMainMenu();
}

void Presenter::ReturnMainMenu() 
{
	int input = 0;
	view->GoBackToMenu();
	view->RegisterInput(input);
	while (input != 9) 
	{
		view->GoBackToMenu();
		view->RegisterInput(input);
	}
	MainMenu();
}

void Presenter::InputCorrectUser(string &name) 
{
	view->AskForName();
	view->RegisterInput(name);
}