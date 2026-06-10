#include "Ward.h"
#include <stdexcept>

// ============================================================
// Ward base
// ============================================================
Ward::Ward(const std::string& name, int capacity, double dailyRate)
    : name_(name), capacity_(capacity), patients_(nullptr), patientCount_(0), dailyRate_(dailyRate) {
    patients_ = new Patient*[capacity_];
}

Ward::~Ward() {
    // We do NOT delete Patient objects — Hospital owns them
    delete[] patients_;
}

bool Ward::remove(int patientId) {
    for (int i = 0; i < patientCount_; ++i) {
        if (patients_[i]->id() == patientId) {
            // shift left
            for (int j = i; j < patientCount_ - 1; ++j)
                patients_[j] = patients_[j + 1];
            --patientCount_;
            return true;
        }
    }
    return false;
}

double Ward::occupancyFraction() const {
    if (capacity_ == 0) return 0.0;
    return static_cast<double>(patientCount_) / capacity_;
}

bool Ward::operator<(const Ward& other) const {
    return occupancyFraction() < other.occupancyFraction();
}

bool Ward::operator>(const Ward& other) const {
    return occupancyFraction() > other.occupancyFraction();
}

bool Ward::operator==(const Ward& other) const {
    return occupancyFraction() == other.occupancyFraction();
}

// ============================================================
// GeneralWard — accepts any patient
// ============================================================
GeneralWard::GeneralWard(const std::string& name, int capacity, double dailyRate)
    : Ward(name, capacity, dailyRate) {}

bool GeneralWard::admit(Patient& p) {
    if (patientCount_ >= capacity_) return false;
    patients_[patientCount_++] = &p;
    return true;
}

// ============================================================
// ICU — only critical patients
// ============================================================
ICU::ICU(const std::string& name, int capacity, double dailyRate)
    : Ward(name, capacity, dailyRate) {}

bool ICU::admit(Patient& p) {
    if (!p.isCritical()) return false;
    if (patientCount_ >= capacity_) return false;
    patients_[patientCount_++] = &p;
    return true;
}

// ============================================================
// SurgicalWard — only patients with a scheduled operation
// ============================================================
SurgicalWard::SurgicalWard(const std::string& name, int capacity, double dailyRate)
    : Ward(name, capacity, dailyRate) {}

bool SurgicalWard::admit(Patient& p) {
    if (!p.hasScheduledOperation()) return false;
    if (patientCount_ >= capacity_) return false;
    patients_[patientCount_++] = &p;
    return true;
}
