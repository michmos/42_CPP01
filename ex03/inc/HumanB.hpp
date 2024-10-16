
#ifndef  HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include "colors.hpp"

class HumanB
{
	Weapon		*_weapon;
	std::string _name;

public:
	HumanB(const std::string &name);
	~HumanB();

	void	attack() const;
	void	setWeapon(Weapon &weapon);
};

#endif // ! HUMANA_HPP
