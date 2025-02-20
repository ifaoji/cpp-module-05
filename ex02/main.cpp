#include <cassert>
#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

void PrintHeader(const std::string &header) {

  std::cout << "----" << std::endl
            << header << std::endl
            << "----" << std::endl;
}

int main() {
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
    foo.beSigned(hubert);

    try {
      foo.execute(hubert);
    } catch (const AForm::GradeTooLowException &) {
      std::cout << "Catched grade too low exception" << std::endl;
    }
  }
}
