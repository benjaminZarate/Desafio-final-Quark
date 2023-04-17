#pragma once
#include <string>
using namespace std;
class Partner
{
protected:
	string name;
	string lastname;
	int id;
public:
	string GetName();
	string GetLastname();
	string GetFullName();
};

