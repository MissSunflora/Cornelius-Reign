/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjebrtanico@myseneca.ca												*
*	Student Number: 104497185															*
*****************************************************************************************/

// TODO: header safeguards
#ifndef SICT_CAKE_H
#define SICT_CAKE_H

// TODO: sict namespace
namespace sict
{
	// TODO: define the structure CellPhone in the sict namespace
	struct CellPhone
	{
		//cellphone model name that contains 32 characters, including null
		//holes the description of the cellphone model
		char m_model[32];
		//floating point number in double precision
		//stores the price of cellphone
		double m_price;
	};
	// TODO: declare the function display(...),
	//         also in the sict namespace
	//display function to displa the phone model and the phone price
	void display(const CellPhone&); //a query
	void display(const CellPhone[] , int );
}

#endif



