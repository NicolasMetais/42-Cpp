#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat alice("Alice", 50);
		Bureaucrat bob("Bob", 140);

		Form contract("Contract A", 100, 50);
		Form top_secret("Top Secret", 10, 5);

		std::cout << "\n== Initial State ==" << std::endl;
		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << contract << std::endl;
		std::cout << top_secret << std::endl;

		std::cout << "\n== Attempting to sign forms ==" << std::endl;

		// Bob essaie de signer contract (il a une note de 140, requis : 100)
		try {
			contract.beSigned(bob);
		} catch (const std::exception& e) {
			std::cout << "Bob can't sign Contract A: " << e.what() << std::endl;
		}

		// Alice essaie de signer contract (il a une note de 50, requis : 100)
		try {
			contract.beSigned(alice);
			std::cout << "Alice successfully signed Contract A." << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Alice can't sign Contract A: " << e.what() << std::endl;
		}

		// Alice essaie de signer un formulaire qu'elle ne peut pas signer
		try {
			top_secret.beSigned(alice);
		} catch (const std::exception& e) {
			std::cout << "Alice can't sign Top Secret: " << e.what() << std::endl;
		}

		std::cout << "\n== Final State ==" << std::endl;
		std::cout << contract << std::endl;
		std::cout << top_secret << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Unhandled exception: " << e.what() << std::endl;
	}

	return 0;
}