/*
** EPITECH PROJECT, 2018
** SickKoala.hpp
** File description:
** Exercice 02 - The Patient
*/

#ifndef _KOALA_H
#define _KOALA_H

#include <algorithm>
#include <iostream>
#include <string>

class SickKoala {
	private:
	std::string name;

	public:
	SickKoala(std::string);
	~SickKoala();

	void poke();
	bool takeDrug(std::string);
	void overDrive(std::string);
	std::string getName();
};

#endif