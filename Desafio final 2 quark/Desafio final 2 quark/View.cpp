#include "View.h"

#include <iostream>
using namespace std;

void View::CleanScreen()
{
	system("cls");
}

void View::MainMenu()
{
	CleanScreen();
	cout << "Quark Library \n" << endl;
	cout << "------------- \n" << endl;
	cout << "What you want to do \n" << endl;
	cout << "1) Register partner\n" << endl;
	cout << "2) Borrow a book \n" << endl;
	cout << "3) Loan history \n" << endl;
	cout << "4) Returns made \n" << endl;
	cout << "5) Return a book \n" << endl;
}

void View::EnterMessage(string message) 
{
	cout << message << "\n" << endl;
}

void View::AskForBook()
{
	CleanScreen();
	cout << "Enter the the book that you want \n" << endl;
}

void View::AskForCopybook(string bookName) 
{
	cout << bookName + " editions \n" << endl;
	cout << "Select an edition \n" << endl;
}

void View::AskForName()
{
	CleanScreen();
	cout << "Enter your name \n" << endl;
}

void View::AskForLastname()
{
	cout << "Enter your lastname \n" << endl;
}

void View::AskIfWantToBeVIP()
{
	cout << "Do you want to be a VIP \n" << endl;
	cout << "1) Yes \n" << endl;
	cout << "2) No \n" << endl;
}

void View::LoanHistoryTitle()
{
	CleanScreen();
	cout << "LOAN HISTORY \n" << endl;
	cout << "------------ \n" << endl;
}

void View::RegisterInput(int& input)
{
	cin >> input;
}

void View::RegisterInput(string& input)
{
	cin >> input;
}

void View::GoBackToMenu() 
{
	cout << "Press 9 to go back to the main menu \n" << endl;
}