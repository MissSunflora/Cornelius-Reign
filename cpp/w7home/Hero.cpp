/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjbertanico@myseneca.ca												*
*	Student Number: 104497185	                                                        *
*	Workshop 7: Derived Classes (Hero)														*
*	Date: 3.13.2019																		*
*****************************************************************************************/

#include <cstring>
#include "Hero.h"

using namespace std;
namespace sict
{
	Hero::Hero()
	{
		m_name[0] = '\0';
		m_health = 0;
		m_attack = 0;
	}

	Hero::Hero(const char *name, int health, int attack) {
		if ((name[0] != '\0') && (health > 0) && (attack > 0))
		{
			strncpy(m_name, name, 40);
			m_health = health;
			m_attack = attack;
		}
		else {
			*this = Hero();
		}
	}

	void Hero::operator-=(int attack)
	{
		if (attack > 0)
		{
			if (isAlive())
				m_health -= attack;

			if (m_health < 0)
			{
				m_health = 0;
			}
		}
	}

	bool Hero::isAlive() const
	{
		if (m_health > 0)
			return true;
		else
			return false;
	}

	int Hero::attackStrength() const
	{
		if (m_name[0] == '\0' && m_health == 0 && m_attack == 0)
		{
			return 0;
		}
		else {
			return m_attack;
		}
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero)
	{
		if (hero.attackStrength() != 0) {
			os << hero.m_name;
			return os;
		}
		else {
			os << "No hero";
			return os;
		}
	}

	const Hero& operator*(const Hero& first, const Hero& second)
	{
		Hero one = first;
		Hero two = second;
		Hero winner;

		for (int i = 0; i < max_rounds && one.isAlive() != 0 && two.isAlive() != 0; i++) {
			one -= two.attackStrength();
			two -= one.attackStrength();

			if (one.isAlive() == false || two.isAlive() == false) {
				cout << "Ancient Battle! " << one << " vs " << two << " : Winner is ";

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