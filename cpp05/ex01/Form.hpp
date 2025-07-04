#pragma once
#include <iostream>
#include <Bureaucrat.hpp>

class Form{
	private:
		std::string const 	name;
		bool				sign;
		const int					grade_sign;
		const int					grade_exec;

	public:
		Form();
		Form(std::string name, int grade_sign, int grade_exec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
		};
		std::string getName() const;
		bool getSign() const;
		int  getGradeSign() const;
		int  getGradeExec() const;
		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);
