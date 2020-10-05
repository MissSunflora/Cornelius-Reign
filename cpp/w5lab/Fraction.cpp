// TODO: insert header files
/********************************************************
*	Name: Nesa Rosmar Jan Bertanico						*
*	Seneca Email: nrjebrtanico@myseneca.ca			    *
*	Student Number: 104497185							*
*	Workshop 5 Lab: FRACTIONS							*
*********************************************************/


// TODO: continue the namespace
#include <iostream>
#include <cstring>
#include "Fraction.h"

using namespace std;

namespace sict {


	// TODO: implement the default constructor
	Fraction::Fraction() // default constructor
	{
	
		m_denominator = 0;
		m_numerator = 0;
	}


	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numerator, int denominator)
	{
		if (numerator > 0  && denominator > 0 )
		{
			this->m_numerator = numerator;
			this->m_denominator = denominator;
			reduce();
		}
		else
		{
			*this = Fraction();
		}
	}


	// TODO: implement the max 
	int Fraction::max() const// a private query that returns the greater of the numerator and denominator
	{
		if (m_numerator > m_denominator)
		{
			return m_numerator;
		}
		else
			return m_denominator;
	}

	// TODO: implement the min query
	int Fraction::min() const // – a private query that returns the lesser of the numerator and denominator
	{
		if (m_numerator > m_denominator)
		{
			return m_denominator;
		}
		else
			return m_numerator;
	}


	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}


	// TODO: implement the reduce modifier
	void Fraction::reduce() // – a private modifier that reduces the numerator and denominator by dividing each by their greatest common divisor
	{
		if (isEmpty() == false)
		{
			int divisor = gcd();

			m_numerator = m_numerator / divisor;
			m_denominator = m_denominator / divisor;
		}

	}


	// TODO: implement the display query
	void Fraction::display() const// – sends the fraction to standard output in the following form if the object holds a valid fraction and its denominator is not unit - valued(1)
	{
		if (isEmpty() == true)
		{
			cout << "no fraction stored";
		}
		else
		{
			if (m_denominator == 1)
			{
				cout << m_numerator;
			}
			else
			{
				cout << m_numerator << "/" << m_denominator;
			}
		}
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const
	{
		if (m_denominator == 0)
			return true;
		else
			return false;
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const// – a public member query that receives an unmodifiable reference to a Fraction object,
	{
		Fraction rhsTemp(0, 0);

		if ((isEmpty() == false) && (rhs.isEmpty() == false)) //if not empty
		{
			rhsTemp.m_numerator = ((m_numerator * rhs.m_denominator) + (rhs.m_numerator * m_denominator)); //((num0 * dem1) + (num1 * dem0))
			rhsTemp.m_denominator = ((m_denominator * rhs.m_denominator)); //(dem0 * dem1)
		}
		return rhsTemp; //(temp (dem0, dem1))
	}

}
