#include "Intern.hpp"
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    srand(time(NULL));
	Intern RandomDude;
	Bureaucrat boss("Boss", 1);
	std::cout << "Shrubbery" << std::endl;
	AForm* shrubbery = RandomDude.makeForm("shrubbery", "UN ARBRE");
	boss.signForm(*shrubbery);
	boss.executeForm(*shrubbery);
	delete shrubbery;
	std::cout << "\nRobotomy Form" << std::endl;
	AForm* robotomy = RandomDude.makeForm("robotomy", "R2D2");
	boss.signForm(*robotomy);
	boss.executeForm(*robotomy);
	delete robotomy;
	std::cout << "\nPresidential" << std::endl;
	AForm* presidential = RandomDude.makeForm("presidential", "BOB");
	boss.signForm(*presidential);
	boss.executeForm(*presidential);
	delete presidential;
	std::cout << "\nInvalid" << std::endl;
	AForm* invalid = RandomDude.makeForm("invalid", "Yes");
	if (invalid)
		delete invalid;
	return 0;
}

