/********************************************************
*	Name: Nesa Rosmar Jan Bertanico						*
*	Seneca Email: nrjebrtanico@myseneca.ca		        *
*	Student Number: 104497185					        *
*	Workshop MILESTONE 2								*
*	DATE: 3/27/19										*
********************************************************/

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include <iostream>
#include "ErrorState.h"
#include "iProduct.h"
#include "Utilities.h"

namespace ama 
{
	class Product : public iProduct	
	{
		const char m_type;
		char m_sku[max_length_sku];
		char m_unit[max_length_unit];
		char* m_name;	
		int m_qtyOnhand;
		int m_qtyNeeded;
		double m_price;
		int m_tax;
		bool taxStatus;
		ErrorState errorState;

	protected:
		void message(const char* pText);
		bool isClear() const;

	public:
		Product(char type = 'N'); 
		Product(const char* sku, const char* name, const char* unit, double price = 0, int qtyNeeded = 0, int qtyOnhand = 0, bool tax = true);
		Product(const Product& object);
		~Product();
		Product& operator=(const Product& obj);
		void sku(char sku[max_length_sku+1]);
		void unit(char unit[max_length_unit+1]);
		void name(const char* name);
		const char type() const;
		const char* name() const;
		double oneTax() const;
		int operator+=(int cnt);
		bool operator==(const char* sku) const;
		bool operator>(const char* sku) const;
		bool operator>(const iProduct& other) const;
		int qtyAvailable() const;
		int qtyNeeded() const;
		double total_cost() const;
		bool isEmpty() const;
		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;
	};

}

#endif
