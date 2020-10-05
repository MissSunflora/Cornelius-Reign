/********************************************
*	Name: Nesa Rosmar Jan Bertanico			*
*	Seneca Email: nrjebrtanico@myseneca.ca	*
*	Student Number: 104497185				*
*	Workshop MILESTONE 5					*
*	Date: 04/06/2019						*
*********************************************/
#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include <iostream>
#include "Product.h"
#include "Date.h"
#include "ErrorState.h"
#include "iProduct.h"
#include "Utilities.h"

namespace ama {
	class Perishable
		: public Product
	{
		Date expiryDate;
	public:
		Perishable();
		std::ostream& write(std::ostream& out, int writeMode) const;
		std::istream& read(std::istream& in, bool interractive);
	};
}


#endif // !AMA_PERISHABLE_H



