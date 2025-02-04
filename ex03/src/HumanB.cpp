
#include "../inc/HumanB.hpp"

HumanB::HumanB(const std::string &name) : _weapon(nullptr), _name(name) {
	#ifdef DEBUG
	std::cout << BLUE << "HumanB " << _name << " created with weapon " << RESET << std::endl;
	#endif // DEBUG
}

HumanB::~HumanB() {
	#ifdef DEBUG
	std::cout << BLUE << "HumanB " << _name << " destroyed" << RESET << std::endl;
	#endif // !DEBUG
}

void	HumanB::attack() const {
	if (_weapon)
		std::cout << _name << "attacks with " << _weapon->getType() << std::endl;
	else
		std::cout << _name << "no weapon to attack " << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
