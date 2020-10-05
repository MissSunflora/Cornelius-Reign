/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjbertanico@myseneca.ca												*
*	Student Number: 104497185	                                                        *
*	Workshop 7: Derived Classes (Hero)														*
*	Date: 3.13.2019																		*
*****************************************************************************************/

#ifndef SICT_HERO_H
#define SICT_HERO_H

#include <iostream>


namespace sict
{
	const int max_rounds = 100;

	class Hero
	{
		char m_name[40];
		int m_health;
		int m_attack;


	public:
		Hero();
		Hero(const char *name, int health, int attack);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};


	const Hero& operator*(const Hero& first, const Hero& second);
}



#endif // !SICT_HERO_H

