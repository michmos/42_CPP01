
#include "../inc/Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) {
	#ifdef DEBUG
	std::cout << BLUE << "Weapon " << _type << " created" << RESET << std::endl;
	#endif // DEBUG
}

Weapon::~Weapon() {
	#ifdef DEBUG
	std::cout << BLUE << "Weapon " << _type << " destroyed" << RESET << std::endl;
	#endif // DEBUG
}

const std::string&	Weapon::getType() const {
	return(_type);
}

void	Weapon::setType(const std::string &type) {
	_type = type;
}
