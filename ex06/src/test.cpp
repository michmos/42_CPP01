
#include <iostream>
#include <limits>

int main(void)
{
	int	choice;

	std::cout << "Enter your choice: 1, 2, 3\n";
	while (true) {
		std::cin >> choice;
		if (std::cin.eof())
		{
			std::cout << "Stdin closed\n";
			return (0);
		}
		if (!std::cin.fail())
			break;
		std::cout << "Wrong input. Please try again\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}


	switch (choice) {
		default:
			std::cout << "Wrong choice\n";
			break;
		case 1:
			std::cout << "You choose 1\n";
		case 2:
			std::cout << "You choose 2\n";
		case 3:
			std::cout << "You choose 3\n";
	}

	return 0;
}
