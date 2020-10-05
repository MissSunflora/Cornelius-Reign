/************************************************
*	Name: Nesa Rosmar Jan Bertanico				*
*	Seneca Email: nrjebrtanico@myseneca.ca      *
*	Student Number: 104497185	                *
*	Workshop 8 Home: Account					*
*	Dated March 24 2019							*
************************************************/
#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H


#include "Account.h"
namespace sict
{
	class ChequingAccount :
		public Account
	{
		double m_transFee;
		double m_monthlyFee;

	public:
		ChequingAccount(double balance, double transFee, double monthlyFee);
		bool credit(double amount);
		bool debit(double amount);
		void monthEnd();
		void display(ostream& out) const;

		///ChequingAccount();
		//~ChequingAccount();
	};
}

#endif // !SICT_CHEQUINGACCOUNT_H


