/*
** EPITECH PROJECT, 2018
** SickKoala.cpp
** File description:
** Exercice 02 - The Patient
*/

#include <iostream>
#include <fstream>
#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
	this->name = name;
}

SickKoala::~SickKoala()
{
	std::cout << "Mr." << this->name << ": Kreooogg!! I'm cuuuured!\n" << '\0';
	this->name.clear();
}

void SickKoala::poke()
{
	std::cout << "Mr." << this->name << ": Gooeeeeerrk!!\n" << '\0';
}

bool SickKoala::takeDrug(std::string drug)
{
	if (drug == "Buronzand") {
		std::cout << "Mr." << this->name << ": And you'll sleep right away!\n" << '\0';
		return (true);
	}

	std::transform(drug.begin(), drug.end(), drug.begin(), ::tolower);
	if (drug == "mars") {
		std::cout << "Mr." << this->name << ": Mars, and it kreogs!\n" << '\0';
		return (true);
	}

	std::cout << "Mr." << this->name << ": Goerkreog!\n" << '\0';
	return (false);
}

void SickKoala::overDrive(std::string msg)
{
	size_t i;
	std::string k = "Kreog!";
	
	while ((i = msg.find(k)) != std::string::npos)
		msg.replace(i, k.size(), "1337!");
	std::cout << "Mr." << this->name << ": " << msg << '\0';
}

std::string SickKoala::getName()
{
	return (this->name);
}