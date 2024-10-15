
#include "../inc/ex01.hpp"

int	main(int argc, char *argv[])
{
	Zombie	*pZombie;
	int		num;

	if (argc != 3) {
		std::cerr << "Usage: ./zombies <num> <name>" << std::endl;
		return (0);
	}

	// get num
	try {
		num = std::stoi(argv[1]);
	} catch (...) {
		std::cerr << "Num argument wrong or too big" << std::endl;
		return (0);
	}

	// test
	pZombie = zombieHorde(num, argv[2]);
	if (!pZombie) {
		return (1);
	}

	for (int i = 0; i < num; ++i) {
		pZombie[i].announce();
	}

	// deallocate objects
	for (int i = 0; i < num; ++i) {
		pZombie[i].~Zombie();
	}
	operator delete (pZombie);
	return (0);
}
