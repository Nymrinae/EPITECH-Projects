/*
** EPITECH PROJECT, 2018
** KoalaNurse.cpp
** report description:
** Exercice 03 - The Nurse
*/

#include "SickKoala.hpp"
#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int id)
{
	this->id = id;
	this->isWorking = false;
}

KoalaNurse::~KoalaNurse()
{
	std::cout << "Nurse " << this->id << ": Finally some rest !\n" << '\0';	
	this->id = 0;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *SickKoala)
{
 	if(SickKoala)
		SickKoala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string report)
{
	std::string	drug = "";
	std::ifstream	file(report.c_str());
	std::string	name = report.substr(0, report.find(".report"));

	if (file.is_open()) {
		file >> drug;
		std::cout << "Nurse " << this->id << ": Kreog ! Mr." << name << " needs a " << drug << "!\n" << '\0';
	}
	return (drug);
}

void KoalaNurse::timeCheck()
{
	if (this->isWorking == false) {
		std::cout << "Nurse " << this->id << ": Time to get to work!\n" << '\0';
		this->isWorking = true;
	}
	else if (this->isWorking) {
		std::cout << "Nurse " << this->id << ": Time to go home to my eucalyptus forest !\n" << '\0';
		this->isWorking = false;
	}
}