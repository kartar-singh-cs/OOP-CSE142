#pragma once
#include "Patient.h"
#include "StaffMember.h"
#include <string>

// ============================================================
// Appointment (value type — holds pointers, does not own)
// ============================================================
struct Appointment {
    Patient*     patient;
    StaffMember* staff;
    std::string  date;
    std::string  timeSlot;

    Appointment(Patient& p, StaffMember& s, const std::string& date, const std::string& slot)
        : patient(&p), staff(&s), date(date), timeSlot(slot) {}
};

// ============================================================
// AppointmentBook — owns a dynamic array of Appointments
// ============================================================
class AppointmentBook {
    Appointment** entries_;
    int count_;
    int capacity_;

    void grow();

public:
    AppointmentBook();
    ~AppointmentBook();
    AppointmentBook(const AppointmentBook&)            = delete;
    AppointmentBook& operator=(const AppointmentBook&) = delete;

    // Returns false if double-booking detected
    bool add(const Appointment& appt);
    bool cancel(Patient& p, StaffMember& s, const std::string& date, const std::string& slot);

    // Retrieve appointments for a staff member on a given date
    // Caller receives a heap-allocated array; caller must delete[] it
    Appointment** getAppointmentsForStaff(StaffMember& s, const std::string& date, int& outCount) const;

    // Retrieve all appointments for a patient
    Appointment** getAppointmentsForPatient(Patient& p, int& outCount) const;
};
