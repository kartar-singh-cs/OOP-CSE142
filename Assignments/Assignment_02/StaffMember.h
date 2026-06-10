#pragma once
#include "Person.h"

class StaffMember : public Person {
protected:
    double salary_;
    std::string department_;

public:
    StaffMember(const std::string& name, const std::string& dob, const std::string& phone,
                double salary, const std::string& department);
    virtual ~StaffMember() = default;

    virtual double calculateBillingRate() const = 0;

    double salary()                    const { return salary_; }
    const std::string& department()    const { return department_; }
    virtual std::string role()         const = 0;
};
