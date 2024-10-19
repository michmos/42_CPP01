
#include "../inc/Harl.hpp"
#include <array>
#include <cstddef>

Harl::Harl() {
	#ifdef DEBUG
	std::cout << "Harl object created" << std::endl;
	#endif // DEBUG
}

Harl::~Harl() {
	#ifdef DEBUG
	std::cout << "Harl object destroyed" << std::endl;
	#endif // DEBUG
}

void Harl::debug() {
	std::cout << "[DEBUG]:\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "[INFO]:\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "[WARNING]:\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "[ERROR]:\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	size_t	i;

	std::array<std::string, 4> levels = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < levels.size(); ++i) {
		if (levels[i] == level)
		{
			break;
		}
	}

	switch (i) {
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
	}
}
