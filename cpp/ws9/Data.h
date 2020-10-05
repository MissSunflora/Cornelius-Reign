// OOP244 Workshop 9: Function Templates
// File: Data.h
// Version: 2.0
// Date: 2017/12/15
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the templated functions and the answers prototype
///////////////////////////////////////////////////
/************************************************
*	Name: Nesa Rosmar Jan Bertanico				*
*	Seneca Email: nrjebrtanico@myseneca.ca      *
*	Student Number: 104497185	                *
*	Workshop 9 Lab: TEMPLATES					*
*************************************************/
#ifndef SICT_DATA_H
#define SICT_DATA_H

#include <iostream>
#include <cstring>


namespace sict {
	const int valueLargest = 1000000000; //9 zeroes
	const int valueSmallest = 0;
	const int width = 20; //widthDesc
	
	const int COLUMN_WIDTH = 15; // These number defines the output column width for a single data field

	// max returns the largest item in data
	template<typename T>
	T max(const T* data, int n) //n = size
	{
		T temp = valueSmallest;
		for (int i = 0; i < n; i++)
		{
			if (temp < data[i])
			{
				temp = data[i];
			}
		}
		return temp;
	}

	// min returns the smallest item in data
	template<typename T>
	T min(const T* data, int n)
	{
		T temp = valueLargest;
		for (int i = 0; i < n; i++)
		{
			if (temp > data[i]) //100000 > 500
			{
				temp = data[i];
			}
		}
		return temp;
	}

	// sum returns the sum of n items in data 
	template<typename T>
	T sum(const T* data, int n)
	{
		T temp = 0;
		for (int i = 0; i < n; i++)
		{
			temp += data[i];
		}
		return temp;
	}

	// average returns the average of n items in data
	template<typename T>
	double average(const T* data, int n)
	{
		return sum(data, n) / n;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan

	template<typename T>
	bool read(std::istream& input, T* data, int n)
	{
		for (int i = 0; i < n; i++)
		{
			input.ignore();
			input >> data[i];
			if (input.fail())
				return false;
		}
		return true;
	}
		
	// display inserts n items of data into std::cout 
	template<typename T>
	void display(const char* name, const T* data, int n)
	{
		// Set Width and justify to the right
		std::cout.width(20);
		std::cout << std::right << name;

		for (int i = 0; i < n; ++i)
		{
			std::cout.width(15);
			std::cout << data[i];
		}
		std::cout << "\n";
	};


	//bool readRow(std::istream& input, const char* name, int* data, int n);
	template<typename T>
	T readRow(std::istream& input, const char* name, T* data, int n) 
	{
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
			// wrong row
			std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			ok = read(input, data, n);// read the data array

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);

}


#endif // !SICT_DATA_H
