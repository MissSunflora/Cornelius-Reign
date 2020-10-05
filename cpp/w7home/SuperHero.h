/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjbertanico@myseneca.ca												*
*	Student Number: 104497185	                                                        *
*	Workshop 7: Derived Classes (Hero)														*
*	Date: 3.17.2019																		*
*****************************************************************************************/

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include "Hero.h"

namespace sict
{
	class SuperHero : public Hero
	{
		int m_bonus;
		int m_defend;

	public:
		SuperHero();
		SuperHero(const char *name, int health, int attack, int bonus, int defend);
		int attackStrength() const;
		int defend() const;
	};


	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif


