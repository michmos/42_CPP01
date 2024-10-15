
#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	#ifdef DEBUG
	std::cout << "name constructor called" << std::endl;
	#endif
}

Zombie::Zombie() {
	#ifdef DEBUG
	std::cout << "dflt constructor called" << std::endl;
	#endif
}

Zombie::~Zombie() {
	std::cout << _name << " destroyed" << std::endl;
}

void	Zombie::announce() const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

