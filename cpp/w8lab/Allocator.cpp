/************************************************
*	Name: Nesa Rosmar Jan Bertanico				*
*	Seneca Email: nrjebrtanico@myseneca.ca      *
*	Student Number: 104497185	                *
*	Workshop 8 Lab: Account						*
*	Dated March 20 2019							*
************************************************/
#include "SavingsAccount.h"

namespace sict {
	
	const double m_interest = 0.05;
	
	//from iAccount?
	iAccount* CreateAccount(const char* type, double balance) {
		iAccount *temp = nullptr;
		if (type[0] == 'S'){
			temp = new SavingsAccount(balance, m_interest);	
		}
		return temp;
		
	}
}