#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::NameToForm Intern::kNameToForms[3] = {
    {"shrubbery creation", &Intern::createShrubberyCreationForm},
    {"robotomy request", &Intern::createRobotomyRequestForm},
    {"presidential pardon", &Intern::createPresidentialPardonForm},
};

Intern::Intern() {
}

Intern::Intern(const Intern &) {
}

Intern::~Intern() {
}

Intern &Intern::operator=(const Intern &) {
    return *this;
}

AForm *Intern::makeForm(const std::string &form_name,
                        const std::string &form_target) const {
    Intern::AFormFactoryPtr factory = NULL;
    for (size_t i = 0; i < sizeof(kNameToForms) / sizeof(kNameToForms[0]);
         i++) {
        if (kNameToForms[i].name != form_name) {
            continue;
        }

        factory = kNameToForms[i].factory;
    }

    if (factory == NULL) {
        std::cout << "Intern could not create form `" << form_name
                  << "`, because it does not exist" << std::endl;

        return NULL;
    }

    AForm *created_form = (this->*factory)(form_target);

    return created_form;
}

AForm *Intern::createShrubberyCreationForm(
    const std::string &form_target) const {
    return new ShrubberyCreationForm(form_target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &form_target) const {
    return new RobotomyRequestForm(form_target);
}

AForm *Intern::createPresidentialPardonForm(
    const std::string &form_target) const {
    return new PresidentialPardonForm(form_target);
}
