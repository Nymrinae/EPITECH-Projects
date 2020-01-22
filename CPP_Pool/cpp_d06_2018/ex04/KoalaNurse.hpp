/*
** EPITECH PROJECT, 2018
** KoalaNurse.hpp
** File description:
** Exercice 03 - The Nurse
*/

#ifndef _NURSE_H
#define _NURSE_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

class KoalaNurse {
	private:
	int id;
	bool isWorking;

	public:
	KoalaNurse(int id);
	~KoalaNurse();

	void		giveDrug(std::string drug, SickKoala *SickKoala);
	std::string	readReport(std::string report);
	void		timeCheck();
};

#endif