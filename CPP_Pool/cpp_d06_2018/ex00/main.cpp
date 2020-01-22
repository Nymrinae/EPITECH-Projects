/*
** EPITECH PROJECT, 2018
** cpp_d06
** File description:
** Exercice 01 - Iostream
*/

#include <iostream>
#include <fstream>

void my_cat(char **av, int i);

int main(int ac, char **av)
{
	if (ac == 1)
		std::cerr << "my_cat: Usage: ./my_cat file [...]\n" << '\0';

	for (int i = 1; i < ac; i++)
		my_cat(av, i);
	return (0);
}

void my_cat(char **av, int i)
{
	std::string line;

	std::ifstream bite(av[i], std::ios::in);
	if (bite.is_open()) {
		while (getline(bite, line))
			std::cout << line << '\n';
		bite.close();
	} else 
		std::cerr << "my_cat: " << av[i] <<  ": No such file or directory\n" << '\0';
}