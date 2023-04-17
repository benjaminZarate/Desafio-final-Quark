#include "Loan.h"
#include "Partner.h"
#include "Book.h"
#include <chrono>
#include <ctime>

Loan::Loan(Book *copy, Partner *partner)
{
	this->copyBook = copy;
	this->partner = partner;

	const auto now = std::chrono::system_clock::now();
	const auto conversion = std::chrono::system_clock::to_time_t(now);

	tm time;
	localtime_s(&time, &conversion);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%d/%m/%y %H:%M:%S", &time);

	date = std::string(buffer);
}