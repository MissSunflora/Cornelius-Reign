/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjebrtanico@myseneca.ca												*
*	Student Number: 104497185															*
*****************************************************************************************/

// TODO: include the necessary headers

// TODO: the sict namespace

    // TODO: definition for display(...) 


#include <iostream>
#include "CellPhone.h"

using namespace std;

namespace sict
{
	//stores the input from client and displays it
	void display(const CellPhone& phone)
	{
		cout << "Phone " << phone.m_model << " costs $" << phone.m_price << "!" << endl;
	}
	
}
