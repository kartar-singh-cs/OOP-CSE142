#pragma once
#include <ostream>
#include <string>

class Bill {
    double treatmentCost_;
    double wardStayCost_;
    double adminFee_;
    std::string patientName_;

public:
    Bill(double treatmentCost, double wardStayCost, double adminFee, const std::string& patientName);
    Bill();

    double total() const { return treatmentCost_ + wardStayCost_ + adminFee_; }
    const std::string& patientName() const { return patientName_; }

    Bill operator+(const Bill& other) const;
    bool operator==(const Bill& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Bill& b);
};
