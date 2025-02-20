#include <cassert>
#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void PrintHeader(const std::string &header) {

  std::cout << "----" << std::endl
            << header << std::endl
            << "----" << std::endl;
}

int main() {
  srand(time(NULL));

  {
    PrintHeader("Shrubbery");

    ShrubberyCreationForm foo;

    Bureaucrat signer("Signer", 145);
    foo.beSigned(signer);

    Bureaucrat executor("Executor", 137);
    foo.execute(executor);
  }

  {
    PrintHeader("Shrubbery Not Signed");

    Bureaucrat hubert("Hubert", 1);
    ShrubberyCreationForm foo;

    try {
      foo.execute(hubert);
    } catch (const AForm::NotSignedException &) {
      std::cout << "Catched not signed exception" << std::endl;
    }
  }

  {
    PrintHeader("Shrubbery Execute Grade Too Low");

    ShrubberyCreationForm foo;

    Bureaucrat signer("Signer", 145);
    foo.beSigned(signer);

    Bureaucrat executor("Executor", 138);
    try {
      foo.execute(executor);
    } catch (const AForm::GradeTooLowException &) {
      std::cout << "Catched grade too low exception" << std::endl;
    }
  }

  {
    PrintHeader("Robotomy");

    RobotomyRequestForm foo("Hubert");

    Bureaucrat signer("Signer", 72);
    foo.beSigned(signer);

    Bureaucrat executor("Executor", 45);
    foo.execute(executor);
  }

  {
    PrintHeader("Robotomy Not Signed");

    RobotomyRequestForm foo("Hubert");

    Bureaucrat executor("Executor", 45);
    try {
      foo.execute(executor);
    } catch (const AForm::NotSignedException &) {
      std::cout << "Catched not signed exception" << std::endl;
    }
  }

  {
    PrintHeader("Robotomy Execute Grade Too Low");

    RobotomyRequestForm foo("Hubert");

    Bureaucrat signer("Signer", 72);
    foo.beSigned(signer);

    Bureaucrat executor("Executor", 46);
    try {
      foo.execute(executor);
    } catch (const AForm::GradeTooLowException &) {
      std::cout << "Catched grade too low exception" << std::endl;
    }
  }

  {
    PrintHeader("Robotomization Is Random");

    Bureaucrat hubert("Hubert", 1);
    RobotomyRequestForm foo("Herbert");

    foo.beSigned(hubert);

    for (int i = 0; i < 10; i++) {
      foo.execute(hubert);
    }
  }
}
