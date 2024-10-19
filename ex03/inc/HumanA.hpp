
#ifndef  HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include "colors.hpp"

class HumanA
{
	Weapon 		&_weapon;
	std::string _name;

public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();

	void	attack() const;
};

#endif // ! HUMANA_HPP
