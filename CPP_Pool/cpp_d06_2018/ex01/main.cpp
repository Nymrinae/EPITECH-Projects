/*
** EPITECH PROJECT, 2018
** cpp_d06
** File description:
** Exercice 1 - Temperature Conversion
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

#define CELSIUS 'C'
#define FAHRENHEIT 'F'
#define BUFF_SIZE 1024 * sizeof(char)

float convert_temp(char scale, float value)
{
	float to_f = (value * 9 / 5) + 32;
	float to_c = (value - 32) * 5 / 9;

	return ((scale == 'C' ? to_f : to_c));
}

int main()
{
	float temp;
	float number;
	std::string type;
	std::string inv_temp;

	std::cin >> temp >> type;
	inv_temp = (type == "Celsius" ? "Fahrenheit" : "Celsius");

	number = convert_temp(type[0], temp);
	std::cout.precision(3);
		std::cout << std::setw(16) << std::fixed << number << std::setw(16) << inv_temp << '\n';
	return (0);
}