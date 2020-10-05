/************************************************
*	Name: Nesa Rosmar Jan Bertanico				*
*	Seneca Email: nrjebrtanico@myseneca.ca      *
*	Student Number: 104497185	                *
*	Workshop 8 Lab: Account						*
*	Dated March 20 2019							*
************************************************/
#include "SavingsAccount.h"
#include "ChequingAccount.h"


namespace sict {
	
	const double m_interest = 0.05;
	const double m_tFee = 0.50;
	const double m_mFee = 2.00;
	

	iAccount* CreateAccount(const char* type, double balance) {
		
		if (type[0] == 'S'){
			iAccount* Stemp = new SavingsAccount(balance, m_interest);
			return Stemp;
		}else if (type[0] == 'C') {
			iAccount* Ctemp = new ChequingAccount(balance, m_tFee, m_mFee);
			return Ctemp;
		}
		else
		{
			return nullptr;
		}
		
	};
}