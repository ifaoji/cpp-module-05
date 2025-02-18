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

    Bureaucrat hubert("Hubert", 1);
    ShrubberyCreationForm foo;

    foo.beSigned(hubert);
    foo.execute(hubert);
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
    PrintHeader("Shrubbery Grade Too Low");

    Bureaucrat hubert("Hubert", 145);
    ShrubberyCreationForm foo;

    foo.beSigned(hubert);

    try {
      foo.execute(hubert);
    } catch (const AForm::GradeTooLowException &) {
      std::cout << "Catched grade too low exception" << std::endl;
    }
  }
}
