/************************************************
*	Name: Nesa Rosmar Jan Bertanico				*
*	Seneca Email: nrjebrtanico@myseneca.ca      *
*	Student Number: 104497185	                *
*	Workshop 8 Home: Account					*
*	Dated March 24 2019							*
************************************************/
#include "ChequingAccount.h"

using namespace std;
namespace sict
{
	ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee): Account(balance)
	{
		if (transFee > 0)
			m_transFee = transFee;
		else
			m_transFee = 0.0;
		
		if (monthlyFee > 0)
			m_monthlyFee = monthlyFee;
		else
			m_monthlyFee = 0.0;
	}

	bool ChequingAccount::credit(double amount)
	{
		if (amount > 0)
		{
			Account::credit(amount);
			Account::debit(m_transFee);
			return true;
		}
		else
			return false;
	}
	bool ChequingAccount::debit(double amount)
	{
		if (amount > 0)
		{
			Account::debit(amount);
			Account::debit(m_transFee);
			return true;
		}
		else
			return false;
	}

	void ChequingAccount::monthEnd()
	{
		debit(m_monthlyFee-m_transFee);
	}
	
	void ChequingAccount::display(ostream& out) const
	{
		out << "Account type: Chequing" << endl;

		out.setf(std::ios::fixed);
		out.precision(2);

		out << "Balance: $" << balance() << endl;
		out << "Per Transaction Fee: " << m_transFee << endl;
		out << "Monthly Fee: " << m_monthlyFee << endl;

		out.unsetf(std::ios::fixed);
	}
}


