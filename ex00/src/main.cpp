
#include "../inc/ex00.hpp"

int	main(void)
{
	randomChump("peter");

	Zombie	*pZombie = new Zombie("heaper");
	pZombie->announce();
	delete pZombie;

	// Zombie *arrZombie = new Zombie[10];

	return (0);
}
