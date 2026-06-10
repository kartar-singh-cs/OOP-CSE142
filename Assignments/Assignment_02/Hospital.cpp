#include "Hospital.h"
#include <cstring>

// ============================================================
// Hospital
// ============================================================
Hospital::Hospital()
    : live_(nullptr), liveCount_(0), liveCap_(0),
      archive_(nullptr), archiveCount_(0), archiveCap_(0),
      discharged_(nullptr), dischargedCount_(0), dischargedCap_(0) {}

Hospital::~Hospital() {
    for (int i = 0; i < liveCount_;    ++i) delete live_[i];
    for (int i = 0; i < archiveCount_; ++i) delete archive_[i];
    for (int i = 0; i < dischargedCount_; ++i) delete discharged_[i];
    delete[] live_;
    delete[] archive_;
    delete[] discharged_;
}

void Hospital::growLive() {
    int newCap = (liveCap_ == 0) ? 8 : liveCap_ * 2;
    Patient** bigger = new Patient*[newCap];
    for (int i = 0; i < liveCount_; ++i) bigger[i] = live_[i];
    delete[] live_;
    live_    = bigger;
    liveCap_ = newCap;
}

void Hospital::growArchive() {
    int newCap = (archiveCap_ == 0) ? 8 : archiveCap_ * 2;
    Patient** bigger = new Patient*[newCap];
    for (int i = 0; i < archiveCount_; ++i) bigger[i] = archive_[i];
    delete[] archive_;
    archive_    = bigger;
    archiveCap_ = newCap;
}

void Hospital::growDischarged() {
    int newCap = (dischargedCap_ == 0) ? 8 : dischargedCap_ * 2;
    DischargeRecord** bigger = new DischargeRecord*[newCap];
    for (int i = 0; i < dischargedCount_; ++i) bigger[i] = discharged_[i];
    delete[] discharged_;
    discharged_    = bigger;
    dischargedCap_ = newCap;
}

int Hospital::findLiveIndex(int id) const {
    for (int i = 0; i < liveCount_; ++i)
        if (live_[i]->id() == id) return i;
    return -1;
}

void Hospital::admit(const Patient& p) {
    if (liveCount_ == liveCap_) growLive();
    live_[liveCount_++] = new Patient(p);  // deep copy
}

bool Hospital::discharge(int patientId, double dailyRate) {
    int idx = findLiveIndex(patientId);
    if (idx < 0) return false;

    Patient* p = live_[idx];

    // Record bill and ward before moving
    Bill b = p->generateBill(dailyRate);
    if (dischargedCount_ == dischargedCap_) growDischarged();
    discharged_[dischargedCount_++] = new DischargeRecord(p->ward(), b);

    // Move to archive (transfer ownership)
    if (archiveCount_ == archiveCap_) growArchive();
    archive_[archiveCount_++] = p;

    // Remove from live array (shift)
    for (int j = idx; j < liveCount_ - 1; ++j)
        live_[j] = live_[j + 1];
    --liveCount_;

    return true;
}

bool Hospital::isAdmitted(int id) const {
    return findLiveIndex(id) >= 0;
}

bool Hospital::isArchived(int id) const {
    for (int i = 0; i < archiveCount_; ++i)
        if (archive_[i]->id() == id) return true;
    return false;
}

Patient** Hospital::filterPatients(std::function<bool(const Patient&)> pred, int& outCount) const {
    // Two-pass: count then fill
    int n = 0;
    for (int i = 0; i < liveCount_; ++i)
        if (pred(*live_[i])) ++n;

    outCount = n;
    if (n == 0) return nullptr;

    Patient** result = new Patient*[n];
    int idx = 0;
    for (int i = 0; i < liveCount_; ++i)
        if (pred(*live_[i])) result[idx++] = live_[i];

    return result;
}

Patient** Hospital::sortPatients(std::function<bool(const Patient&, const Patient&)> cmp,
                                  int& outCount) const {
    outCount = liveCount_;
    if (liveCount_ == 0) return nullptr;

    Patient** result = new Patient*[liveCount_];
    for (int i = 0; i < liveCount_; ++i) result[i] = live_[i];

    // Bubble sort (good enough for assignment; no std::sort allowed via algorithm)
    for (int i = 0; i < liveCount_ - 1; ++i)
        for (int j = 0; j < liveCount_ - 1 - i; ++j)
            if (cmp(*result[j + 1], *result[j])) {
                Patient* tmp = result[j];
                result[j]   = result[j + 1];
                result[j + 1] = tmp;
            }

    return result;
}

StaffMember** Hospital::filterStaff(StaffMember** staff, int staffCount,
                                     std::function<bool(const StaffMember&)> pred,
                                     int& outCount) const {
    int n = 0;
    for (int i = 0; i < staffCount; ++i)
        if (pred(*staff[i])) ++n;

    outCount = n;
    if (n == 0) return nullptr;

    StaffMember** result = new StaffMember*[n];
    int idx = 0;
    for (int i = 0; i < staffCount; ++i)
        if (pred(*staff[i])) result[idx++] = staff[i];

    return result;
}

double Hospital::wardRevenue(const std::string& wardName) const {
    double total = 0.0;
    for (int i = 0; i < dischargedCount_; ++i)
        if (discharged_[i]->wardName == wardName)
            total += discharged_[i]->bill.total();
    return total;
}

Patient** Hospital::patientsTreatedBy(const std::string& staffName, int& outCount) const {
    int total = liveCount_ + archiveCount_;
    if (total == 0) { outCount = 0; return nullptr; }

    Patient** combined = new Patient*[total];
    for (int i = 0; i < liveCount_;    ++i) combined[i]              = live_[i];
    for (int i = 0; i < archiveCount_; ++i) combined[liveCount_ + i] = archive_[i];

    int n = 0;
    for (int i = 0; i < total; ++i)
        if (combined[i]->hasTreatmentBy(staffName)) ++n;

    outCount = n;
    Patient** result = nullptr;
    if (n > 0) {
        result = new Patient*[n];
        int idx = 0;
        for (int i = 0; i < total; ++i)
            if (combined[i]->hasTreatmentBy(staffName))
                result[idx++] = combined[i];
    }
    delete[] combined;
    return result;
}
