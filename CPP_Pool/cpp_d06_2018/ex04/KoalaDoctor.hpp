/*
** EPITECH PROJECT, 2018
** KoalaDoctor.hpp
** File description:
** Exercice 04 - The Doctor
*/

#ifndef _DOCTOR_H
#define _DOCTOR_H

#include <algorithm>
#include <iostream>
#include <string>
#include "SickKoala.hpp"

class KoalaDoctor {
	private:
	std::string name;
	bool isWorking = false;

	public:
	KoalaDoctor(std::string);
	~KoalaDoctor();

	void diagnose(SickKoala *SickKoala);
	void timeCheck();
};

#endif