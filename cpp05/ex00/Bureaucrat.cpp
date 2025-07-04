#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat&other) {
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

std::string	Bureaucrat::getName() const {
	return name;
}

unsigned int Bureaucrat::getGrade() const {
	return grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

void	Bureaucrat::upGrade() {
	if (grade <= 1)
		throw	GradeTooHighException();
	this->grade -= 1;
}

void	Bureaucrat::downGrade() {
	if (grade >= 150)
		throw	GradeTooLowException();
	this->grade += 1;
}

Bureaucrat::~Bureaucrat() {
}