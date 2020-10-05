/********************************************
*	Name: Nesa Rosmar Jan Bertanico			*
*	Seneca Email: nrjebrtanico@myseneca.ca	*
*	Student Number: 104497185				*
*	Workshop MILESTONE 5					*
*	Date: 04/06/2019						*
*********************************************/
#ifndef AMAAPP_H
#define AMAAPP_H

#include <iostream>
#include "iProduct.h"
#include "Utilities.h"
#include "Product.h"
#include "Sort.h"

namespace ama
{
	class AmaApp
	{

		char m_filename[256];
		iProduct* m_products[100];
		int m_noOfProducts;
		AmaApp(const AmaApp& object) = delete;	
		AmaApp& operator = (const AmaApp& object) = delete;
		void pause() const;
		int menu() const;
		void loadProductRecords();
		void saveProductRecords() const;
		void listProducts() const; 
		void deleteProductRecord(iProduct* product); 
		void sort();
		iProduct* find(const char* sku) const;
		void addQty(iProduct* product);
		void addProduct(char tag);
		

	public:
		AmaApp(const char* filename);
		~AmaApp();
		int run();
	};
}


#endif // !AMA_AMAAPP_H
