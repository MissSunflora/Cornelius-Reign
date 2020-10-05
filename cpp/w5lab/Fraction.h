/********************************************************
*	Name: Nesa Rosmar Jan Bertanico						*
*	Seneca Email: nrjebrtanico@myseneca.ca			    *
*	Student Number: 104497185							*
*	Workshop 5 Lab: FRACTIONS							*
*********************************************************/

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// TODO: create namespace
namespace sict{
	// TODO: define the Fraction class
	class Fraction {
	// TODO: declare instance variables 	
		int m_numerator;
		int m_denominator;

	// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce(); 
		int gcd() const; 
		

	public:
	// TODO: declare public member functions
		Fraction(); // default constructor
		Fraction(int numerator, int denominator);
		bool isEmpty() const; 
		void display() const;

	// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
		//Fraction (const Fraction& other);
		//~Fraction();
	};
}

#endif

