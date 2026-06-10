#include "Roles.h"
#include <iostream>

// ============================================================
// GP
// ============================================================
GP::GP(const std::string& name, const std::string& dob, const std::string& phone,
       double salary, const std::string& department, double consultationFee)
    : StaffMember(name, dob, phone, salary, department),
      consultationFee_(consultationFee) {}

void GP::display() const {
    std::cout << "--- General Practitioner ---" << std::endl;
    std::cout << "Name             : " << name_             << std::endl;
    std::cout << "ID               : " << id_               << std::endl;
    std::cout << "DOB              : " << dob_              << std::endl;
    std::cout << "Phone            : " << phone_            << std::endl;
    std::cout << "Department       : " << department_       << std::endl;
    std::cout << "Salary           : PKR " << salary_       << std::endl;
    std::cout << "Consultation Fee : PKR " << consultationFee_ << "/hr" << std::endl;
}

// ============================================================
// Surgeon
// ============================================================
Surgeon::Surgeon(const std::string& name, const std::string& dob, const std::string& phone,
                 double salary, const std::string& department,
                 const std::string& specialisation, double operationFee)
    : StaffMember(name, dob, phone, salary, department),
      specialisation_(specialisation), operationFee_(operationFee) {}

void Surgeon::display() const {
    std::cout << "--- Surgeon ---" << std::endl;
    std::cout << "Name             : " << name_           << std::endl;
    std::cout << "ID               : " << id_             << std::endl;
    std::cout << "DOB              : " << dob_            << std::endl;
    std::cout << "Phone            : " << phone_          << std::endl;
    std::cout << "Department       : " << department_     << std::endl;
    std::cout << "Salary           : PKR " << salary_     << std::endl;
    std::cout << "Specialisation   : " << specialisation_ << std::endl;
    std::cout << "Operation Fee    : PKR " << operationFee_ << "/op" << std::endl;
}

// ============================================================
// Nurse
// ============================================================
Nurse::Nurse(const std::string& name, const std::string& dob, const std::string& phone,
             double salary, const std::string& department,
             const std::string& assignedWard, double careHourlyFee)
    : StaffMember(name, dob, phone, salary, department),
      assignedWard_(assignedWard), careHourlyFee_(careHourlyFee) {}

void Nurse::display() const {
    std::cout << "--- Nurse ---" << std::endl;
    std::cout << "Name             : " << name_          << std::endl;
    std::cout << "ID               : " << id_            << std::endl;
    std::cout << "DOB              : " << dob_           << std::endl;
    std::cout << "Phone            : " << phone_         << std::endl;
    std::cout << "Department       : " << department_    << std::endl;
    std::cout << "Salary           : PKR " << salary_    << std::endl;
    std::cout << "Assigned Ward    : " << assignedWard_  << std::endl;
    std::cout << "Care Hourly Fee  : PKR " << careHourlyFee_ << "/hr" << std::endl;
}
