// OOP244 Workshop 9: Function Templates
// File: Data.cpp
// Version: 2.0.1
// Date: 2017/12/17
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the answers and readRow functions
// Chris     2017.12.17 removed answers to Q1
///////////////////////////////////////////////////
/************************************************
*	Name: Nesa Rosmar Jan Bertanico				*
*	Seneca Email: nrjebrtanico@myseneca.ca      *
*	Student Number: 104497185	                *
*	Workshop 9 Lab: TEMPLATES					*
*************************************************/

#include <iostream>
#include "Data.h"

using namespace std;
namespace sict {
	// answers outputs statistics for visual validation of data

	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		double popChange = population[n - 1] - population[0];

		//Population change from 2000 to 2004 is 12.23 million 
		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << popChange / 1000000 << " million" << endl;
		cout.unsetf(ios::fixed);

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		//Violent Crime trend is down 

		cout << "Violent Crime trend is ";
		if (violentCrime[0] > violentCrime[n - 1])
			cout << "down" << endl;
		else
			cout << "up" << endl;

		// Q3 print the GTA number accurate to 0 decimal places
		//There are 1.23 million Grand Theft Auto incidents on average a year 

		//double
		popChange = average(grandTheftAuto, n) / 1000000;

		cout << "There are ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << popChange << " million Grand Theft Auto incidents on average a year" << endl;
		cout.unsetf(ios::fixed);


		// Q4. Print the min and max violentCrime rates
		//The Minimum Violent Crime rate was 463 
		int minn = min(violentCrimeRate, n);
		cout << "The Minimum Violent Crime rate was " << minn << endl;


		//The Maximum Violent Crime rate was 506
		int maxx = max(violentCrimeRate, n);
		cout << "The Maximum Violent Crime rate was " << maxx <<endl;
	}
}