#include <Intern.hpp>
#include <ShrubberyCreationForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* createShrubbery(std::string const& target) {
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string const& target) {
	return new RobotomyRequestForm(target);
}

AForm* createPresidential(std::string const& target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
	std::string forms[3] = {
		"shrubbery",
		"robotomy",
		"presidential"
	};

	AForm* (*createForm[3])(std::string const&) = {
			createShrubbery,
			createRobotomy,
			createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == name)
		{
			std::cout << "Intern creates " << name <<std::endl;
			return createForm[i](target);
		}
	}
	std::cout << "Intern doesn't know the form: " << name <<std::endl;
	return NULL;

}