#pragma once
#include <iostream>
#include <functional>

class Harl
{
public:
	Harl();
	void complain(std::string level);
private:
	void debug();
	void info();
	void warning();
	void error();

	//Je veux stocker des pointeur vers une fonction membre de Harl (debug, error etc..)
	//Je creer un alias de harl pour rendre le code plus lisible et pointer sur les fonctions membre
	typedef void (Harl::*HarlPtr)();
	HarlPtr fonctions[4];
	std::string levels[4];
};