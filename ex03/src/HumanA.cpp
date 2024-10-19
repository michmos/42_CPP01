
#include "../inc/HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _weapon(weapon), _name(name) {
	#ifdef DEBUG
	std::cout << BLUE << "HumanA " << _name << " created with weapon " << _weapon.getType() << RESET << std::endl;
	#endif // DEBUG
}

HumanA::~HumanA() {
	#ifdef DEBUG
	std::cout << BLUE << "HumanA " << _name << " destroyed" << RESET << std::endl;
	#endif // !DEBUG
}

void	HumanA::attack() const {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
