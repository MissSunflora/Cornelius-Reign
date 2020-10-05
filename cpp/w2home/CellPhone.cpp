/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjebrtanico@myseneca.ca												*
*	Student Number: 104497185															*
*****************************************************************************************/

// TODO: include the necessary headers
#include <iostream>
#include "CellPhone.h"

using namespace std;

// TODO: the sict namespace
namespace sict
{

// TODO: definition for display(...) 
	//stores the input from client and displays it
	void display(const CellPhone& phone)
	{
		cout << "Phone " << phone.m_model << " costs $" << phone.m_price << "!" << endl;
	}
	void display(const CellPhone Phones[], int count)	
	{
		double small;
		//cheapest
		cout << "------------------------------" << endl
			<< "Phones available at the mall:" << endl
		 	<< "------------------------------" << endl;
			for (int i = 0; i < count; i++) {
				small = Phones[0].m_price;
				if (Phones[i].m_price < small)
				{
					small = Phones[i].m_price;
				}
				cout << i+1 << ". Phone " << Phones[i].m_model<< " costs $" << Phones[i].m_price << "!" << endl;
			}
			
			cout << "------------------------------" << endl
			<< "The cheapest phone costs $" << small  <<"."<< endl
			<< "------------------------------" << endl;


	}
	
}
