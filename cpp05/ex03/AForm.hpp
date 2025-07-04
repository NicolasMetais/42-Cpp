#pragma once
#include <iostream>
#include <Bureaucrat.hpp>

class AForm{
	private:
		std::string const 	name;
		bool				sign;
		const int			grade_sign;
		const int			grade_exec;

	public:
		AForm();
		AForm(std::string name, int grade_sign, int grade_exec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
		};
		class IsSignable : public std::exception {
		public:
			const char* what() const throw();
		};
		std::string getName() const;
		bool getSign() const;
		int  getGradeSign() const;
		int  getGradeExec() const;
		void beSigned(const Bureaucrat& bureaucrat);
		void executable(Bureaucrat const& executor) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
