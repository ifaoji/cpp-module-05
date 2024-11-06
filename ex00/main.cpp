#include <iostream>

#include "Bureaucrat.hpp"

void PrintHeader(const std::string &header) {

  std::cout << "----" << std::endl
            << header << std::endl
            << "----" << std::endl;
}

int main() {
  {
    PrintHeader("Instanciate with invalid grades");

    try {
      Bureaucrat hubert("Hubert", 0);
    } catch (const Bureaucrat::GradeTooHighException &) {
      std::cout << "Catched grade too high exception" << std::endl;
    }

    try {
      Bureaucrat hubert("Hubert", 151);
    } catch (const Bureaucrat::GradeTooLowException &) {
      std::cout << "Catched grade too low exception" << std::endl;
    }
  }

  {
    PrintHeader("Increment should decrease the grade");

    Bureaucrat hubert("Hubert", 2);
    std::cout << hubert;
    hubert.incrementGrade();
    std::cout << hubert;
  }

  {
    PrintHeader("Decrement should increase the grade");

    Bureaucrat hubert("Hubert", 1);
    std::cout << hubert;
    hubert.decrementGrade();
    std::cout << hubert;
  }

  {
    PrintHeader("Increment 1 should throw exception");

    Bureaucrat hubert("Hubert", 1);

    try {
      hubert.incrementGrade();
    } catch (const Bureaucrat::GradeTooHighException &) {
      std::cout << "Catched grade too high exception" << std::endl;
    }
  }

  {
    PrintHeader("Decrement 150 should throw exception");

    Bureaucrat hubert("Hubert", 150);

    try {
      hubert.decrementGrade();
    } catch (const Bureaucrat::GradeTooLowException &) {
      std::cout << "Catched grade too low exception" << std::endl;
    }
  }

  {
    PrintHeader("Subject");

    try {
      Bureaucrat hubert("Hubert", 0);
    } catch (std::exception &e) {
      std::cout << "Catched " << e.what() << std::endl;
    }

    try {
      Bureaucrat hubert("Hubert", 151);
    } catch (std::exception &e) {
      std::cout << "Catched " << e.what() << std::endl;
    }
  }
}
