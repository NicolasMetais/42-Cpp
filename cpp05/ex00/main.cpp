#include <Bureaucrat.hpp>
#include <iostream>

int main() {
    //valid grade
    try {
        Bureaucrat b1("Alice", 50);
        std::cout << b1 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    //increment
    try {
        Bureaucrat b2("Bob", 100);
        std::cout << b2 << std::endl;
        b2.upGrade();
        std::cout << b2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    //decrement
    try {
        Bureaucrat b3("Charlie", 2);
        std::cout << b3 << std::endl;
        b3.downGrade();
        std::cout << b3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    //Wrong grade
    try {
        Bureaucrat b4("David", 151);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    //Wrong grade
    try {
        Bureaucrat b5("Eve", 0);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    //increment too high
    try {
        Bureaucrat b6("Frank", 1);
        std::cout << b6 << std::endl;
        b6.upGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    //decrement too low
    try {
        Bureaucrat b7("Grace", 150);
        std::cout << b7 << std::endl;
        b7.downGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}