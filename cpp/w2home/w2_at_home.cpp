/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjebrtanico@myseneca.ca												*
*	Student Number: 104497185															*
*****************************************************************************************/

// Workshop 2 - Dynamic Memory
// Version 1.0
// Date: 31/08/2018
// Author: Cornel

// TODO: include headers
#include <iostream>
#include "CellPhone.h" 

using namespace std;
using namespace sict;

void read(sict::CellPhone& phone);

int main()
{
	int count = 0;


	CellPhone* pPhones = nullptr;
	CellPhone* Phones = nullptr;


	cout << "==========" << endl
	     << "Input data" << endl
	     << "==========" << endl
	     << "Enter the number of phones: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	// TODO: allocate dynamic memory here for the pPhones pointer
	pPhones = new CellPhone[count];


	for (int i = 0; i < count; ++i) {
		cout << "Phone #" << i + 1 << ": " << endl;
		// TODO: add code to accept user input for Phone i
		cout << "Enter the model of the Phone: ";
		cin >> pPhones[i].m_model;
		cout << "Enter the price for phone " << pPhones[i].m_model << ": ";
		cin >> pPhones[i].m_price;

	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
	     << "The 1st phone entered is" << endl
	     << "------------------------------" << endl;
	sict::display(pPhones[0]);
	cout << "------------------------------" << endl << endl;

	// expand the array of Phones by 1 element
	// TODO: allocate dynamic memory for count + 1 Phones
	Phones = new CellPhone[count + 1];
	for (int i = 0; i < count; i++)
	{
		// TODO: copy elements from original array into this newly allocated array
		Phones[i] = pPhones[i];//pPhones = new CellPhone[count + 1];
	}

	// TODO: deallocate the dynamic memory for the original array
	
	delete[] pPhones;

	// TODO: copy the address of the newly allocated array into pPhones pointer
	
	pPhones = Phones;

	// add the new Phone
	
	cout << "==========\n"
	     << "Input data\n"
	     << "==========\n"
	     << "Phone #" << count + 1 << ": " << endl;
	
	// TODO: accept input for the new element in the array
	
	cout << "Enter the model of the Phone: ";
	cin >> Phones[count].m_model;
	cout << "Enter the price for phone " << Phones[count].m_model << ": ";
	cin >> Phones[count].m_price;

	count++;
	cout << "==========\n" << endl;

	// testing that the overload of "display(...)" works
	sict::display(pPhones, count);
	cout << endl;

	// TODO: deallocate the dynamic memory here
	delete[] pPhones;
	pPhones = nullptr;

	return 0;
}


// read accepts data for a Phone from standard input
void read(CellPhone& phone)
{
	cout << "Enter the model of the Phone: ";
	cin.get(phone.m_model, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the price for phone " << phone.m_model << ": ";
	cin >> phone.m_price;
	cin.ignore(2000, '\n');
}
