#include "StaffMember.h"

StaffMember::StaffMember(const std::string& name, const std::string& dob, const std::string& phone,
                         double salary, const std::string& department)
    : Person(name, dob, phone), salary_(salary), department_(department) {}
