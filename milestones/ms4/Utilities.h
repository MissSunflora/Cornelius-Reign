/********************************************************
*	Name: Nesa Rosmar Jan Bertanico						*
*	Seneca Email: nrjebrtanico@myseneca.ca		        *
*	Student Number: 104497185					        *
*	Workshop MILESTONE 2								*
*	DATE: 3/25/19										*
********************************************************/

#ifndef AMA_UTILITIES_H
#define AMA_UTILITIES_H

#include <iostream>
#include "Product.h"

using namespace std;
namespace ama 
{
	double& operator+=(double& total, const  iProduct& prod);
	ostream& operator<<(ostream& out, const  iProduct& prod);
	istream& operator>>(istream& in, iProduct& prod);
	iProduct* createInstance(char tag); // dynamically create instances in the Product hierarchy

}

#endif

