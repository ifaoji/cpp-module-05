#include <unistd.h>

#include <cstdlib>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45), target_("default_target") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request Form", 72, 45), target_(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target_(other.target_) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &rhs) {
    if (this == &rhs) return *this;

    AForm::operator=(rhs);

    // Since `target_` is constant, it cannot be assigned to a new value
    // target_ = rhs.target_;

    return *this;
}

static bool randomBool() {
    bool res = rand() < (RAND_MAX / 2);

    return res;
}

void RobotomyRequestForm::executeUnchecked(const Bureaucrat &) const {
    std::cout << "[Drilling Noises...]" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << '\a';
        std::cout.flush();
        // TODO: Check whether this delay is actually good
        usleep(50 * 1000);
    }

    bool successfully_robotomized = randomBool();

    if (!successfully_robotomized) {
        std::cout << target_ << " was not successfully robotomized"
                  << std::endl;

        return;
    }

    std::cout << target_ << " was robotomized" << std::endl;
}
