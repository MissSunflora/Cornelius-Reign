/************************************************
*	Name: Nesa Rosmar Jan Bertanico				*
*	Seneca Email: nrjebrtanico@myseneca.ca      *
*	Student Number: 104497185	                *
*	Workshop 8 Lab: Account						*
*	Dated March 20 2019							*
************************************************/
#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

#include "iAccount.h"

namespace sict {
	//deriving from iAccount
	//https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/
	class Account : public virtual iAccount {
		double m_iniBal;

	public:

		Account(double balance = 0.0);
		bool credit(double amount);
		bool debit(double amount);
		
	protected:
		double balance() const;

	};
}

#endif // !SICT_ACCOUNT_H
