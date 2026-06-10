#pragma once
#include "StaffMember.h"

// ============================================================
// General Practitioner
// ============================================================
class GP : public StaffMember {
    double consultationFee_;

public:
    GP(const std::string& name, const std::string& dob, const std::string& phone,
       double salary, const std::string& department, double consultationFee);

    double calculateBillingRate() const override { return consultationFee_; }
    std::string role() const override { return "GP"; }
    void display() const override;
    double consultationFee() const { return consultationFee_; }
};

// ============================================================
// Surgeon
// ============================================================
class Surgeon : public StaffMember {
    std::string specialisation_;
    double operationFee_;

public:
    Surgeon(const std::string& name, const std::string& dob, const std::string& phone,
            double salary, const std::string& department,
            const std::string& specialisation, double operationFee);

    double calculateBillingRate() const override { return operationFee_; }
    std::string role() const override { return "Surgeon"; }
    void display() const override;
    const std::string& specialisation() const { return specialisation_; }
    double operationFee() const { return operationFee_; }
};

// ============================================================
// Nurse
// ============================================================
class Nurse : public StaffMember {
    std::string assignedWard_;
    double careHourlyFee_;

public:
    Nurse(const std::string& name, const std::string& dob, const std::string& phone,
          double salary, const std::string& department,
          const std::string& assignedWard, double careHourlyFee);

    double calculateBillingRate() const override { return careHourlyFee_; }
    std::string role() const override { return "Nurse"; }
    void display() const override;
    const std::string& assignedWard() const { return assignedWard_; }
};
