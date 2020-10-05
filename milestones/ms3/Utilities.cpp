/********************************************************
*	Name: Nesa Rosmar Jan Bertanico						*
*	Seneca Email: nrjebrtanico@myseneca.ca		        *
*	Student Number: 104497185					        *
*	Workshop MILESTONE 2								*
*	DATE: 3/25/19										*
********************************************************/
#include <iostream>
#include "Utilities.h"
#include <iomanip>

using namespace std;
namespace ama
{
	double& operator+=(double& total, const Product& prod)
	{	
		//if (prod.taxStatus)
		return (total += prod.total_cost());
	}
	ostream& operator<<(ostream& out, const Product& prod)
	{
		prod.write(out, write_human);

			return out;		
	}

	istream& operator>>(istream& in, Product& prod)
	{
		prod.read(in, true);
		return in;
	}
}
