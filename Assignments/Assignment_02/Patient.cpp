#include "Patient.h"
#include <iostream>
#include <sstream>
#include <cstring>

// ---- helpers ---------------------------------------------------------------

// Parse "YYYY-MM-DD" -> days-since-epoch (simple, good enough for day-diff)
static int dateToDays(const std::string& date) {
    int y = 0, m = 0, d = 0;
    sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d);
    // Approximate: just use days = y*365 + m*30 + d
    return y * 365 + m * 30 + d;
}

// ---- constructors / destructor ---------------------------------------------

Patient::Patient(const std::string& name, const std::string& dob, const std::string& phone,
                 const std::string& diagnosis, const std::string& admissionDate,
                 const std::string& ward, bool critical, bool hasScheduledOperation)
    : Person(name, dob, phone),
      diagnosis_(diagnosis), admissionDate_(admissionDate), ward_(ward),
      critical_(critical), hasScheduledOperation_(hasScheduledOperation),
      treatments_(nullptr), treatmentCount_(0), treatmentCapacity_(0) {}

// Deep copy
Patient::Patient(const Patient& other)
    : Person(other),
      diagnosis_(other.diagnosis_), admissionDate_(other.admissionDate_), ward_(other.ward_),
      critical_(other.critical_), hasScheduledOperation_(other.hasScheduledOperation_),
      treatmentCount_(other.treatmentCount_), treatmentCapacity_(other.treatmentCount_) {
    if (treatmentCapacity_ > 0) {
        treatments_ = new Treatment*[treatmentCapacity_];
        for (int i = 0; i < treatmentCount_; ++i)
            treatments_[i] = new Treatment(*other.treatments_[i]);
    } else {
        treatments_ = nullptr;
    }
}

Patient& Patient::operator=(const Patient& other) {
    if (this == &other) return *this;
    // free existing
    for (int i = 0; i < treatmentCount_; ++i) delete treatments_[i];
    delete[] treatments_;

    Person::operator=(other);
    diagnosis_              = other.diagnosis_;
    admissionDate_          = other.admissionDate_;
    ward_                   = other.ward_;
    critical_               = other.critical_;
    hasScheduledOperation_  = other.hasScheduledOperation_;
    treatmentCount_         = other.treatmentCount_;
    treatmentCapacity_      = other.treatmentCount_;

    if (treatmentCapacity_ > 0) {
        treatments_ = new Treatment*[treatmentCapacity_];
        for (int i = 0; i < treatmentCount_; ++i)
            treatments_[i] = new Treatment(*other.treatments_[i]);
    } else {
        treatments_ = nullptr;
    }
    return *this;
}

// Move constructor: steal pointer, leave other in valid empty state
Patient::Patient(Patient&& other) noexcept
    : Person(std::move(other)),
      diagnosis_(std::move(other.diagnosis_)),
      admissionDate_(std::move(other.admissionDate_)),
      ward_(std::move(other.ward_)),
      critical_(other.critical_),
      hasScheduledOperation_(other.hasScheduledOperation_),
      treatments_(other.treatments_),
      treatmentCount_(other.treatmentCount_),
      treatmentCapacity_(other.treatmentCapacity_) {
    other.treatments_      = nullptr;
    other.treatmentCount_  = 0;
    other.treatmentCapacity_ = 0;
}

Patient& Patient::operator=(Patient&& other) noexcept {
    if (this == &other) return *this;
    for (int i = 0; i < treatmentCount_; ++i) delete treatments_[i];
    delete[] treatments_;

    Person::operator=(std::move(other));
    diagnosis_             = std::move(other.diagnosis_);
    admissionDate_         = std::move(other.admissionDate_);
    ward_                  = std::move(other.ward_);
    critical_              = other.critical_;
    hasScheduledOperation_ = other.hasScheduledOperation_;
    treatments_            = other.treatments_;
    treatmentCount_        = other.treatmentCount_;
    treatmentCapacity_     = other.treatmentCapacity_;
    other.treatments_      = nullptr;
    other.treatmentCount_  = 0;
    other.treatmentCapacity_ = 0;
    return *this;
}

Patient::~Patient() {
    for (int i = 0; i < treatmentCount_; ++i) delete treatments_[i];
    delete[] treatments_;
}

// ---- methods ---------------------------------------------------------------

void Patient::grow() {
    int newCap = (treatmentCapacity_ == 0) ? 4 : treatmentCapacity_ * 2;
    Treatment** bigger = new Treatment*[newCap];
    for (int i = 0; i < treatmentCount_; ++i) bigger[i] = treatments_[i];
    delete[] treatments_;
    treatments_ = bigger;
    treatmentCapacity_ = newCap;
}

void Patient::addTreatment(const Treatment& t) {
    if (treatmentCount_ == treatmentCapacity_) grow();
    treatments_[treatmentCount_++] = new Treatment(t);
}

Bill Patient::generateBill(double dailyRate) const {
    double treatCost = 0.0;
    for (int i = 0; i < treatmentCount_; ++i)
        treatCost += treatments_[i]->cost();

    int days = dateToDays("2026-04-14") - dateToDays(admissionDate_);
    if (days < 1) days = 1;
    double wardStay = days * dailyRate;
    double admin    = 500.0;

    return Bill(treatCost, wardStay, admin, name_);
}

void Patient::display() const {
    std::cout << "--- Patient ---" << std::endl;
    std::cout << "Name          : " << name_          << std::endl;
    std::cout << "ID            : " << id_            << std::endl;
    std::cout << "DOB           : " << dob_           << std::endl;
    std::cout << "Phone         : " << phone_         << std::endl;
    std::cout << "Diagnosis     : " << diagnosis_     << std::endl;
    std::cout << "Admission Date: " << admissionDate_ << std::endl;
    std::cout << "Ward          : " << ward_          << std::endl;
    std::cout << "Critical      : " << (critical_ ? "Yes" : "No") << std::endl;
    std::cout << "Treatments    : " << treatmentCount_ << std::endl;
}

std::string Patient::surname() const {
    size_t pos = name_.rfind(' ');
    if (pos == std::string::npos) return name_;
    return name_.substr(pos + 1);
}

bool Patient::hasTreatmentBy(const std::string& staffName) const {
    for (int i = 0; i < treatmentCount_; ++i)
        if (treatments_[i]->staffName() == staffName) return true;
    return false;
}

const std::string Patient::treatmentNameAt(int i) const {
    return treatments_[i]->name();
}

const std::string Patient::treatmentStaffAt(int i) const {
    return treatments_[i]->staffName();
}

double Patient::treatmentCostAt(int i) const {
    return treatments_[i]->cost();
}
