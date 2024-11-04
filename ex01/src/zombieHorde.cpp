
#include "../inc/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	Zombie	*pZombie = new Zombie[N];

	for (int i =0; i < N; ++i) {
		pZombie[i] = Zombie(name);
	}
	return (pZombie);
}

