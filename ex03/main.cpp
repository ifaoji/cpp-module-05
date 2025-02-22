#include <cassert>
#include <cstdlib>
#include <iostream>

#include "Intern.hpp"

void PrintHeader(const std::string& header) {
    std::cout << "----" << std::endl
              << header << std::endl
              << "----" << std::endl;
}

int main() {
    srand(time(NULL));

    {
        PrintHeader("Intern Shrubbery");

        Intern intern;
        AForm* scf;

        scf = intern.makeForm("shrubbery creation", "target");

        Bureaucrat hubert("Hubert", 1);
        hubert.signForm(*scf);
        scf->execute(hubert);

        delete scf;
    }

    {
        PrintHeader("Intern Robotomy");

        Intern intern;
        AForm* rrf;

        rrf = intern.makeForm("robotomy request", "target");

        Bureaucrat hubert("Hubert", 1);
        hubert.signForm(*rrf);
        rrf->execute(hubert);

        delete rrf;
    }

    {
        PrintHeader("Intern Presidential");

        Intern intern;
        AForm* ppf;

        ppf = intern.makeForm("presidential pardon", "target");

        Bureaucrat hubert("Hubert", 1);
        hubert.signForm(*ppf);
        ppf->execute(hubert);

        delete ppf;
    }

    {
        PrintHeader("Intern Unknown");

        Intern intern;
        AForm* iuf;

        iuf = intern.makeForm("heh i don't exist", "target");

        assert(iuf == NULL);
    }

    {
        PrintHeader("Subject");

        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        delete rrf;
    }
}
