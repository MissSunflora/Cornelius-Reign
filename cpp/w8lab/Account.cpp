/************************************************
*	Name: Nesa Rosmar Jan Bertanico				*
*	Seneca Email: nrjebrtanico@myseneca.ca      *
*	Student Number: 104497185	                *
*	Workshop 8 Lab: Account						*
*	Dated March 20 2019							*
************************************************/

#include "Account.h"

namespace sict {

	Account::Account(double balance) {
		if (balance > 0) {
			m_iniBal = balance;
		}
		else
			m_iniBal = 0.0;
	}

	bool Account::credit(double amount) {
		if (amount > 0) {
			m_iniBal = m_iniBal + amount;
			return true;
		}
		else
			return false;
	}

	
	bool Account::debit(double amount) {
		if (amount > 0) {
			m_iniBal = m_iniBal - amount;
			return true;
		}
		else
			return false;
	}

	double Account::balance() const {
		return m_iniBal;
	}

//virtual ~iAccount() = default;
//virtual bool credit(double amount) = 0;
//virtual bool debit(double amount) = 0;
//virtual void monthEnd() = 0;
//virtual void display(ostream& out) const = 0;
}

