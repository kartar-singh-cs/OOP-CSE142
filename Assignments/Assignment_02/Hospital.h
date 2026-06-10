#pragma once
#include "Patient.h"
#include "StaffMember.h"
#include "Ward.h"
#include "Bill.h"
#include <functional>
#include <vector>
#include <string>

// ============================================================
// Hospital — owns live and archived patients
// ============================================================
class Hospital {
    // Dynamic arrays of Patient* (owned)
    Patient** live_;
    int liveCount_;
    int liveCap_;

    Patient** archive_;
    int archiveCount_;
    int archiveCap_;

    // Dynamic array of (wardName, bill) pairs for discharged patients
    struct DischargeRecord {
        std::string wardName;
        Bill        bill;
        DischargeRecord(const std::string& w, const Bill& b) : wardName(w), bill(b) {}
    };
    DischargeRecord** discharged_;
    int dischargedCount_;
    int dischargedCap_;

    void growLive();
    void growArchive();
    void growDischarged();

    int findLiveIndex(int id) const;

public:
    Hospital();
    ~Hospital();
    Hospital(const Hospital&)            = delete;
    Hospital& operator=(const Hospital&) = delete;

    void admit(const Patient& p);      // copies patient into live list
    bool discharge(int patientId, double dailyRate = 500.0);

    bool isAdmitted(int id) const;
    bool isArchived(int id) const;

    // ---------- functional query interface ----------

    // Returns heap-allocated array of Patient* (non-owning); caller must delete[]
    Patient** filterPatients(std::function<bool(const Patient&)> pred, int& outCount) const;

    // Returns heap-allocated sorted copy; caller must delete[]
    Patient** sortPatients(std::function<bool(const Patient&, const Patient&)> cmp, int& outCount) const;

    // Returns heap-allocated array of StaffMember* — but Hospital doesn't own staff,
    // so we accept an external staff array to search over
    StaffMember** filterStaff(StaffMember** staff, int staffCount,
                              std::function<bool(const StaffMember&)> pred,
                              int& outCount) const;

    double wardRevenue(const std::string& wardName) const;

    // Returns all patients treated by a staff member (by staff name in treatments)
    Patient** patientsTreatedBy(const std::string& staffName, int& outCount) const;
};
