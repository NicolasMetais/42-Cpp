#include <Bureaucrat.hpp>
#include <AForm.hpp>

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
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

int Bureaucrat::getGrade() const {
	return grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low\n";
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

void	Bureaucrat::signForm(AForm& form){
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& excep) {
		std::cout << name << " can't sign " << form.getName() << " because " << excep.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << name << " couldn't execute " << form.getName() << e.what() << std::endl;
	}
}
