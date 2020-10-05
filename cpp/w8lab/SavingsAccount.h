/************************************************
*	Name: Nesa Rosmar Jan Bertanico				*
*	Seneca Email: nrjebrtanico@myseneca.ca      *
*	Student Number: 104497185	                *
*	Workshop 8 Lab: Account						*
*	Dated March 20 2019							*
************************************************/
#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H

#include "Account.h"


namespace sict{

	class SavingsAccount :
		public Account
	{
		double m_intRate;
	public:
		SavingsAccount(double balance, double interestRate);
		void monthEnd();
		void display(ostream& out) const;
	};
}


#endif
