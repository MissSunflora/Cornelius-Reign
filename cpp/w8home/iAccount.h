/************************************************
*	Name: Nesa Rosmar Jan Bertanico				*
*	Seneca Email: nrjebrtanico@myseneca.ca      *
*	Student Number: 104497185	                *
*	Workshop 8 Lab: Account						*
*	Dated March 20 2019							*
************************************************/
#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H

#include <iostream>

using namespace std;
namespace sict {

	class iAccount {
	public:
		//includes a destructor:
		//https://stackoverflow.com/questions/13576055/how-is-default-different-from-for-default-constructor-and-destructor
		virtual ~iAccount() = default;

		//pure virtual public member functions: 
		//https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/

		virtual bool credit(double amount) = 0;
		virtual bool debit(double amount) = 0;
		virtual void monthEnd() = 0;
		virtual void display(ostream& out) const = 0;
	};
	//helper for allocator
	iAccount* CreateAccount(const char* type, double balance);
}
#endif // !SICT_IACCOUNT_H_
