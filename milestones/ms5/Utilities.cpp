/********************************************************
*	Name: Nesa Rosmar Jan Bertanico						*
*	Seneca Email: nrjebrtanico@myseneca.ca		        *
*	Student Number: 104497185					        *
*	Workshop MILESTONE 2								*
*	DATE: 3/27/19										*
********************************************************/
#include <iostream>
#include "Utilities.h"
#include "Perishable.h"
#include <iomanip>

using namespace std;
namespace ama
{
	double& operator+=(double& total, const iProduct& prod)
	{	
		return (total += prod.total_cost());
	}
	ostream& operator<<(ostream& out, const iProduct& prod)
	{
		prod.write(out, write_human);

			return out;		
	}

	istream& operator>>(istream& in, iProduct& prod)
	{
		prod.read(in, true);
		return in;
	}

	iProduct* createInstance(char tag) // dynamically create instances in the Product hierarchy
	{
		if (tag == 'N' || tag == 'n')
			return new Product();//create an object of type product
		else if (tag == 'P' || tag == 'p')
			return new Perishable();
		else
			return nullptr;
	}
}
