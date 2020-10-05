/************************************************
*	Name: Nesa Rosmar Jan Bertanico				*
*	Seneca Email: nrjebrtanico@myseneca.ca      *
*	Student Number: 104497185	                *
*	Workshop 8 Lab: Account						*
*	Dated March 20 2019							*
************************************************/
#include "SavingsAccount.h"

using namespace std;
namespace sict
{
	SavingsAccount::SavingsAccount(double balance, double interestRate): Account(balance) {
		if (interestRate > 0) {

			m_intRate = interestRate;
		}
		else
			m_intRate = 0.0;
	}

	void SavingsAccount::monthEnd() {
		
		double temp = balance() * m_intRate;
		credit(temp);

	}
	void SavingsAccount::display(ostream& out) const { //http://www.cplusplus.com/reference/ios/ios_base/precision/
			
		out << "Account type: Savings" << endl;
		
        	out.setf(ios::fixed);
		out.precision(2);
		
		out << "Balance: $" << balance() << endl;
		out << "Interest Rate (%): " << m_intRate * 100 << endl;
		out.unsetf(ios::fixed);
	}
}