
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class Weapon
{
private:
	std::string	_type;

public:
	Weapon(const std::string &name);
	Weapon();
	~Weapon();

	const std::string& getType() const;
	void	setType(const std::string &type);

};

#endif // !WEAPON_HPP
