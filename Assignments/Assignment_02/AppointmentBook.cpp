#include "AppointmentBook.h"

AppointmentBook::AppointmentBook()
    : entries_(nullptr), count_(0), capacity_(0) {}

AppointmentBook::~AppointmentBook() {
    for (int i = 0; i < count_; ++i) delete entries_[i];
    delete[] entries_;
}

void AppointmentBook::grow() {
    int newCap = (capacity_ == 0) ? 8 : capacity_ * 2;
    Appointment** bigger = new Appointment*[newCap];
    for (int i = 0; i < count_; ++i) bigger[i] = entries_[i];
    delete[] entries_;
    entries_  = bigger;
    capacity_ = newCap;
}

bool AppointmentBook::add(const Appointment& appt) {
    // Check for double-booking: same staff, same date, same slot
    for (int i = 0; i < count_; ++i) {
        if (entries_[i]->staff     == appt.staff &&
            entries_[i]->date      == appt.date  &&
            entries_[i]->timeSlot  == appt.timeSlot) {
            return false; // rejected
        }
    }
    if (count_ == capacity_) grow();
    entries_[count_++] = new Appointment(appt);
    return true;
}

bool AppointmentBook::cancel(Patient& p, StaffMember& s,
                             const std::string& date, const std::string& slot) {
    for (int i = 0; i < count_; ++i) {
        if (entries_[i]->patient  == &p &&
            entries_[i]->staff    == &s &&
            entries_[i]->date     == date &&
            entries_[i]->timeSlot == slot) {
            delete entries_[i];
            for (int j = i; j < count_ - 1; ++j)
                entries_[j] = entries_[j + 1];
            --count_;
            return true;
        }
    }
    return false;
}

Appointment** AppointmentBook::getAppointmentsForStaff(StaffMember& s,
                                                        const std::string& date,
                                                        int& outCount) const {
    // count matching
    int n = 0;
    for (int i = 0; i < count_; ++i)
        if (entries_[i]->staff == &s && entries_[i]->date == date) ++n;

    outCount = n;
    if (n == 0) return nullptr;
    Appointment** result = new Appointment*[n];
    int idx = 0;
    for (int i = 0; i < count_; ++i)
        if (entries_[i]->staff == &s && entries_[i]->date == date)
            result[idx++] = entries_[i];
    return result;
}

Appointment** AppointmentBook::getAppointmentsForPatient(Patient& p, int& outCount) const {
    int n = 0;
    for (int i = 0; i < count_; ++i)
        if (entries_[i]->patient == &p) ++n;

    outCount = n;
    if (n == 0) return nullptr;
    Appointment** result = new Appointment*[n];
    int idx = 0;
    for (int i = 0; i < count_; ++i)
        if (entries_[i]->patient == &p)
            result[idx++] = entries_[i];
    return result;
}
