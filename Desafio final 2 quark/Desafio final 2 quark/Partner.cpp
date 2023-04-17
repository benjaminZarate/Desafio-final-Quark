#include "Partner.h"

string Partner::GetName()
{
	return name;
}

string Partner::GetLastname()
{
	return lastname;
}

string Partner::GetFullName() 
{
	return name + " " + lastname;
}