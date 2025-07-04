#include <RobotomyRequestForm.hpp>
#include <fstream>
#include <ctime>
#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm()
		: AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
		: AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	executable(executor);
	srand(time(NULL));
	int result = rand() % 2;
	if (result)
		std::cout << target << " Robotomized." << std::endl;
	else
		std::cout << "Robotomize Failed." << std::endl;
}

