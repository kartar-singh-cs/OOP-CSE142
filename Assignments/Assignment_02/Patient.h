#pragma once
#include "Person.h"
#include "Treatment.h"
#include "Bill.h"
#include <vector>
#include <string>

class Patient : public Person {
    std::string diagnosis_;
    std::string admissionDate_;
    std::string ward_;
    bool critical_;
    bool hasScheduledOperation_;
    Treatment** treatments_;
    int treatmentCount_;
    int treatmentCapacity_;

    void grow();

public:
    Patient(const std::string& name, const std::string& dob, const std::string& phone,
            const std::string& diagnosis, const std::string& admissionDate,
            const std::string& ward, bool critical = false, bool hasScheduledOperation = false);

    Patient(const Patient& other);            // copy constructor (deep)
    Patient& operator=(const Patient& other); // copy assignment
    Patient(Patient&& other) noexcept;        // move constructor
    Patient& operator=(Patient&& other) noexcept;
    ~Patient();

    void display() const override;
    void addTreatment(const Treatment& t);
    Bill generateBill(double dailyRate = 500.0) const;

    int  treatmentCount()              const { return treatmentCount_; }
    const std::string& diagnosis()     const { return diagnosis_; }
    const std::string& admissionDate() const { return admissionDate_; }
    const std::string& ward()          const { return ward_; }
    bool isCritical()                  const { return critical_; }
    bool hasScheduledOperation()       const { return hasScheduledOperation_; }

    // For sorting by total bill (needs a ward daily rate; we use a fixed default here)
    double totalBill(double dailyRate = 500.0) const { return generateBill(dailyRate).total(); }

    std::string surname() const;
    bool hasTreatmentBy(const std::string& staffName) const;
    const std::string treatmentNameAt(int i)     const;
    const std::string treatmentStaffAt(int i)    const;
    double            treatmentCostAt(int i)     const;
};
