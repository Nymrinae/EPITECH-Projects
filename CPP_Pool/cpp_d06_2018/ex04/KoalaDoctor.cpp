/*
** EPITECH PROJECT, 2018
** SickKoala.cpp
** File description:
** Exercice 02 - The Patient
*/

#include "SickKoala.hpp"
#include "KoalaNurse.hpp"
#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
	this->name = name;
	std::cout << "Dr." << name << "! How do you kreog?\n" << '\0';
	this->isWorking = false;
}

KoalaDoctor::~KoalaDoctor()
{
	this->name.clear();
}

void KoalaDoctor::diagnose(SickKoala *SickKoala)
{
	std::string drugs[] = {
		"mars",
		"Buronzand",
		"Viagra",
		"Extasy",
		"Eucalyptus leaf"
	};
	std::string report = SickKoala->getName() + ".report";
	std::ofstream file(report.c_str(), std::ios::out);

	std::cout << "Dr." << this->name << "So what's goerking you Mr." << SickKoala->getName() << "]?\n" << '\0';
	SickKoala->poke();

	if (file) {
		file << drugs[rand() % 5];
		file.close();
	}
}

void KoalaDoctor::timeCheck()
{
	if (this->isWorking == false) {
		std::cout << "Dr." << this->name << ": Time to get to work!\n" << '\0';
		this->isWorking = true;
	}
	else if (this->isWorking) {
		std::cout << "Dr." << this->name << ": Time to go home to my eucalyptus forest !\n" << '\0';
		this->isWorking = false;
	}
}