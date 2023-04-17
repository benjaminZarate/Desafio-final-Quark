#pragma once
#include <string>
using namespace std;

class View
{
public:
	void CleanScreen();
	void MainMenu();
	void LoanHistoryTitle();
	void AskForName();
	void AskForLastname();
	void AskIfWantToBeVIP();
	void AskForBook();
	void AskForCopybook(string bookName);
	void RegisterInput(string& input);
	void RegisterInput(int& input);
	void GoBackToMenu();
	void EnterMessage(string message);

};

