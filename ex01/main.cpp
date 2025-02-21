#include <cassert>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

void PrintHeader(const std::string &header) {
    std::cout << "----" << std::endl
              << header << std::endl
              << "----" << std::endl;
}

int main() {
    {
        PrintHeader("Instanciate with invalid grades");

        try {
            Form foo("Foo", 0, 150);
        } catch (const Form::GradeTooHighException &) {
            std::cout << "Catched grade too high exception" << std::endl;
        }

        try {
            Form foo("Foo", 150, 0);
        } catch (const Form::GradeTooHighException &) {
            std::cout << "Catched grade too high exception" << std::endl;
        }

        try {
            Form foo("Foo", 151, 1);
        } catch (const Form::GradeTooLowException &) {
            std::cout << "Catched grade too low exception" << std::endl;
        }

        try {
            Form foo("Foo", 1, 151);
        } catch (const Form::GradeTooLowException &) {
            std::cout << "Catched grade too low exception" << std::endl;
        }
    }

    {
        PrintHeader("Print Form To Console");

        Form foo("Foo", 1, 150);

        std::cout << foo << std::endl;
    }

    {
        PrintHeader("Signing Works");

        Bureaucrat hubert("Hubert", 1);
        Form       foo("Foo", 1, 1);

        foo.beSigned(hubert);

        std::cout << "Signed: " << foo.getIsSigned() << std::endl;
    }

    {
        PrintHeader("Signing Fails");

        Bureaucrat hubert("Hubert", 2);
        Form       foo("Foo", 1, 1);

        try {
            foo.beSigned(hubert);
        } catch (const Form::GradeTooLowException &) {
            std::cout << "Catched grade too low exception" << std::endl;
        }

        std::cout << "Signed: " << foo.getIsSigned() << std::endl;
    }

    {
        PrintHeader("Bureaucrat Signes Direct");

        Bureaucrat hubert("Hubert", 1);
        Form       foo("Foo", 1, 1);

        hubert.signForm(foo);
        std::cout << "Signed: " << foo.getIsSigned() << std::endl;
    }

    {
        PrintHeader("Bureaucrat Signes Direct Fails");

        Bureaucrat hubert("Hubert", 150);
        Form       foo("Foo", 1, 1);

        hubert.signForm(foo);
        std::cout << "Signed: " << foo.getIsSigned() << std::endl;
    }
}
