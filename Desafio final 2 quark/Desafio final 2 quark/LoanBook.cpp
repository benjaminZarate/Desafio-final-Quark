#include "LoanBook.h"
#include "Loan.h"

void LoanBook::AddALoan(Loan* loan) 
{
    loans.push_back(loan);
    amountOfLoans++;
}

void LoanBook::RemoveALoan(string bookName) 
{
    if (loans.size() == 0) { return; }
    for (size_t i = 0; i < loans.size(); i++)
    {
        if (loans[i]->copyBook->GetName() == bookName) 
        {
            auto it = next(loans.begin(), i);
            returns.push_back(*it);
            loans.erase(it);
            break;
        }
    }
}
