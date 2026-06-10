#pragma once
#include "Patient.h"
#include <string>

// ============================================================
// Abstract Ward base
// ============================================================
class Ward {
protected:
    std::string name_;
    int capacity_;
    Patient** patients_;   // non-owning: hospital owns Patient objects
    int patientCount_;
    double dailyRate_;

public:
    Ward(const std::string& name, int capacity, double dailyRate);
    virtual ~Ward();

    // No copy / move needed for this design (Hospital owns wards)
    Ward(const Ward&)            = delete;
    Ward& operator=(const Ward&) = delete;

    // Polymorphic admission — each subclass enforces its own rule
    virtual bool admit(Patient& p) = 0;
    virtual std::string type() const = 0;

    bool remove(int patientId);

    double occupancyFraction() const;
    bool   operator<(const Ward& other) const;
    bool   operator>(const Ward& other) const;
    bool   operator==(const Ward& other) const;

    const std::string& name()    const { return name_; }
    int  capacity()              const { return capacity_; }
    int  patientCount()          const { return patientCount_; }
    double dailyRate()           const { return dailyRate_; }
    Patient* patientAt(int i)    const { return patients_[i]; }
};

// ============================================================
// Concrete wards
// ============================================================
class GeneralWard : public Ward {
public:
    GeneralWard(const std::string& name, int capacity, double dailyRate = 500.0);
    bool admit(Patient& p) override;
    std::string type() const override { return "GeneralWard"; }
};

class ICU : public Ward {
public:
    ICU(const std::string& name, int capacity, double dailyRate = 2000.0);
    bool admit(Patient& p) override;
    std::string type() const override { return "ICU"; }
};

class SurgicalWard : public Ward {
public:
    SurgicalWard(const std::string& name, int capacity, double dailyRate = 1500.0);
    bool admit(Patient& p) override;
    std::string type() const override { return "SurgicalWard"; }
};
