/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjbertanico@myseneca.ca												*
*	Student Number: 104497185	                                                        *
*	Workshop 7: Derived Classes (Hero)														*
*	Date: 3.17.2019																		*
*****************************************************************************************/

#include <cstring>
#include "Hero.h"
#include "SuperHero.h"

using namespace std;
namespace sict
{
	SuperHero::SuperHero()
	{
		Hero("", 0, 0);
		m_bonus = 0;
		m_defend = 0;
	}

	SuperHero::SuperHero(const char *name, int health, int attack, int bonus, int defend) : Hero(name, health, attack) {
		if ((name[0] != '\0') && (health > 0) && (attack > 0))
		{
			Hero(name, health, attack);
			m_bonus = bonus;
			m_defend = defend;
		}
		else {
			*this = SuperHero();
			m_bonus = 0;
			m_defend = 0;
		}
	}

	int SuperHero::attackStrength()const
	{
		if (m_bonus == 0 && m_bonus == 0)
			return 0;
		else
			return (Hero::attackStrength() + m_bonus);
	}
	int SuperHero::defend() const
	{
		if (m_bonus == 0 && m_defend == 0)
			return 0;
		else
			return m_defend;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
	{
		SuperHero one = first;
		SuperHero two = second;
		SuperHero winner;

		for (int i = 0; i < max_rounds && one.isAlive() != 0 && two.isAlive() != 0; i++) {
			one -= (two.attackStrength() - one.defend());
			two -= (one.attackStrength() - two.defend());

			if (one.isAlive() == false || two.isAlive() == false) {
				cout << "Super Fight! " << one << " vs " << two << " : Winner is ";

				if (one.isAlive() == false)
					cout << two;
				else
					cout << one;

				cout << " in " << i + 1 << " rounds." << endl;
			}
		}

		if (one.isAlive() && two.isAlive() == false)
			return first;
		else
			return second;
	}

}
