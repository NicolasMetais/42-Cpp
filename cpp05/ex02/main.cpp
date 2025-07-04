#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ShrubberyCreationForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <Bureaucrat.hpp>

int main() {
    srand(time(NULL));
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 1);
        Bureaucrat tom("Tom", 150);

        ShrubberyCreationForm shrubForm("home");
        PresidentialPardonForm pardonForm("Nico");
        RobotomyRequestForm robotForm("Marvin");

        std::cout << "\nShrubbery\n";
        bob.signForm(shrubForm);
        bob.executeForm(shrubForm);

        std::cout << "\nPresidential\n";
        alice.signForm(pardonForm);
        alice.executeForm(pardonForm);

        std::cout << "\nRobotomy\n";
        tom.signForm(robotForm);
        tom.executeForm(robotForm);

        bob.signForm(robotForm);
        bob.executeForm(robotForm);

    } catch (const std::exception& e) {
        std::cerr << "Error " << e.what() << std::endl;
    }
    return 0;
}
