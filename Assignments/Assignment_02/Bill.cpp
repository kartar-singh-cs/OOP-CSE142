#include "Bill.h"
#include <iostream>

Bill::Bill()
    : treatmentCost_(0), wardStayCost_(0), adminFee_(0), patientName_("") {}

Bill::Bill(double treatmentCost, double wardStayCost, double adminFee, const std::string& patientName)
    : treatmentCost_(treatmentCost), wardStayCost_(wardStayCost), adminFee_(adminFee), patientName_(patientName) {}

Bill Bill::operator+(const Bill& other) const {
    return Bill(
        treatmentCost_ + other.treatmentCost_,
        wardStayCost_  + other.wardStayCost_,
        adminFee_      + other.adminFee_,
        patientName_ + " + " + other.patientName_
    );
}

bool Bill::operator==(const Bill& other) const {
    return total() == other.total();
}

std::ostream& operator<<(std::ostream& os, const Bill& b) {
    os << "=== Bill ===" << std::endl;
    os << "Patient      : " << b.patientName_ << std::endl;
    os << "Treatments   : PKR " << b.treatmentCost_ << std::endl;
    os << "Ward Stay    : PKR " << b.wardStayCost_  << std::endl;
    os << "Admin Fee    : PKR " << b.adminFee_      << std::endl;
    os << "TOTAL        : PKR " << b.total()        << std::endl;
    return os;
}
