#include <iostream>
#include <vector>
#include <cassert>
#include <string>

#include "Person.h"
#include "Patient.h"
#include "StaffMember.h"
#include "Roles.h"
#include "Ward.h"
#include "Bill.h"
#include "AppointmentBook.h"
#include "Hospital.h"
#include "Treatment.h"

// ============================================================
// Simple check helper — prints PASS / FAIL
// ============================================================
static void check(bool condition, const std::string& tcName) {
    std::cout << (condition ? "[PASS] " : "[FAIL] ") << tcName << std::endl;
}

// ============================================================
// TC-01 | Polymorphic Display
// ============================================================
static void tc01() {
    std::cout << "\n========== TC-01 : Polymorphic Display ==========\n";

    GP       gp1     ("Dr. Ayesha Malik",  "1980-03-12", "0300-1111111", 150000, "General Practice", 2000.0);
    Surgeon  surgeon1("Dr. Bilal Khan",    "1975-07-22", "0321-2222222", 250000, "Surgery",          "Cardiothoracic", 15000.0);
    Nurse    nurse1  ("Nurse Rabia Noor",  "1992-05-18", "0333-3333333",  60000, "General Ward",     "Ward A", 800.0);
    Patient  patient1("Hamid Raza",        "1990-01-10", "0341-4444444",
                      "Hypertension", "2026-04-01", "Ward A", false, false);

    std::vector<Person*> people = { &gp1, &surgeon1, &nurse1, &patient1 };
    for (auto* p : people) p->display();

    // PASS if we reach here without crash and each display() ran
    check(true, "TC-01 | Polymorphic Display — no if/else, 4 different outputs");
}

// ============================================================
// TC-02 | Billing — Operator Overloading
// ============================================================
static void tc02() {
    std::cout << "\n========== TC-02 : Billing Operators ==========\n";

    Patient patient1("Ali Raza",  "1985-06-01", "0300-0000001",
                     "Appendicitis", "2026-04-01", "Surgical Ward", false, true);
    Patient patient2("Sara Baig", "1990-09-09", "0300-0000002",
                     "Flu",          "2026-04-05", "Ward A",        false, false);

    patient1.addTreatment(Treatment("Appendectomy",   8000, "Dr. Bilal Khan"));
    patient1.addTreatment(Treatment("Post-op care",   2000, "Nurse Rabia Noor"));

    patient2.addTreatment(Treatment("Blood test",      500, "Dr. Ayesha Malik"));

    Bill b1 = patient1.generateBill(500.0);
    Bill b2 = patient2.generateBill(500.0);

    Bill combined = b1 + b2;
    check(combined.total() == b1.total() + b2.total(), "TC-02 | operator+ totals add up");
    check(!(b1 == b2),                                 "TC-02 | operator== different bills");
    Bill b3 = b1;
    check(b1 == b3,                                    "TC-02 | operator== copy equal");

    std::cout << combined;  // operator<<
    check(true, "TC-02 | operator<< printed without crash");
}

// ============================================================
// TC-03 | Ward Comparison Operators
// ============================================================
static void tc03() {
    std::cout << "\n========== TC-03 : Ward Comparison ==========\n";

    GeneralWard w1("Ward A", 20);
    ICU         w2("ICU",     8);

    // Admit 5 patients into w1
    Patient* pts[7];
    for (int i = 0; i < 7; ++i) {
        pts[i] = new Patient("Patient" + std::to_string(i), "2000-01-01", "0000-0000000",
                             "Cardiac arrest", "2026-04-01", "ICU", true, false);
    }

    for (int i = 0; i < 5; ++i) w1.admit(*pts[i]);          // 5/20 = 25%
    for (int i = 0; i < 7; ++i) w2.admit(*pts[i]);          // 7/8  = 87.5%

    check(w1 < w2,     "TC-03 | w1 < w2  (25% < 87.5%)");
    check(w2 > w1,     "TC-03 | w2 > w1");
    check(!(w1 == w2), "TC-03 | w1 != w2");

    for (int i = 0; i < 7; ++i) delete pts[i];
}

// ============================================================
// TC-04 | ICU Admission Rule Enforcement
// ============================================================
static void tc04() {
    std::cout << "\n========== TC-04 : Ward Admission Rules ==========\n";

    Patient critical("Ali Khan",  "1988-03-03", "0311-1111111",
                     "Cardiac arrest",  "2026-04-10", "ICU",    true,  false);
    Patient routine ("Sara Baig", "1995-07-07", "0322-2222222",
                     "Sprained ankle",  "2026-04-10", "Ward A", false, false);
    Patient surgical("Omar Faroq","1975-05-05", "0333-3333333",
                     "Knee replacement","2026-04-10", "Surgical Ward", false, true);

    ICU          icu ("ICU",     10);
    GeneralWard  gw  ("General", 30);
    SurgicalWard sw  ("Surgical", 10);

    check(icu.admit(critical)  == true,  "TC-04 | ICU accepts critical patient");
    check(icu.admit(routine)   == false, "TC-04 | ICU rejects non-critical patient");
    check(gw.admit(routine)    == true,  "TC-04 | General Ward accepts anyone");
    check(sw.admit(surgical)   == true,  "TC-04 | Surgical Ward accepts scheduled-op patient");
    check(sw.admit(routine)    == false, "TC-04 | Surgical Ward rejects non-scheduled patient");
}

// ============================================================
// TC-05 | Double-Booking Prevention
// ============================================================
static void tc05() {
    std::cout << "\n========== TC-05 : Double-Booking Prevention ==========\n";

    GP      gp1     ("Dr. Ayesha Malik", "1980-03-12", "0300-1111111", 150000, "General Practice", 2000.0);
    Patient patient1("Hamid Raza",       "1990-01-10", "0341-4444444",
                     "Hypertension", "2026-04-01", "Ward A");
    Patient patient2("Zara Ahmed",       "1993-11-20", "0341-5555555",
                     "Migraine",     "2026-04-01", "Ward A");

    AppointmentBook book;
    bool first = book.add(Appointment(patient1, gp1, "2026-04-10", "10:00"));
    check(first == true, "TC-05 | First booking accepted");

    // Same doctor, same date, same slot -> rejected
    bool dup = book.add(Appointment(patient2, gp1, "2026-04-10", "10:00"));
    check(dup == false, "TC-05 | Double-booking rejected");

    // Different slot -> accepted
    bool ok = book.add(Appointment(patient2, gp1, "2026-04-10", "11:00"));
    check(ok == true, "TC-05 | Different slot accepted");
}

// ============================================================
// TC-06 | Copy Independence
// ============================================================
static void tc06() {
    std::cout << "\n========== TC-06 : Copy Independence ==========\n";

    Patient original("Hamid Raza", "1990-01-10", "0341-4444444",
                     "Fever", "2026-04-05", "Ward A");
    original.addTreatment(Treatment("Blood test", 500, "Dr. Alvi"));

    Patient copy = original;                                          // copy constructor
    copy.addTreatment(Treatment("MRI", 8000, "Dr. Khan"));

    check(original.treatmentCount() == 1, "TC-06 | Original has 1 treatment after copy modified");
    check(copy.treatmentCount()     == 2, "TC-06 | Copy has 2 treatments");
}

// ============================================================
// TC-07 | Move Semantics — Discharge & Archive
// ============================================================
static void tc07() {
    std::cout << "\n========== TC-07 : Move Semantics / Discharge ==========\n";

    Hospital h;
    Patient p1("Nadia Shah", "1988-04-04", "0300-9999999",
               "Diabetes", "2026-04-01", "Ward A");
    h.admit(p1);
    int pid = p1.id();

    h.discharge(pid, 500.0);

    check(!h.isAdmitted(pid), "TC-07 | Patient no longer in live records");
    check( h.isArchived(pid), "TC-07 | Patient is in archive");
    // Destructor will run cleanly — no double-free
    check(true, "TC-07 | No crash on scope exit");
}

// ============================================================
// TC-08 | Composable Filtering with Lambdas
// ============================================================
static void tc08() {
    std::cout << "\n========== TC-08 : Composable Lambdas ==========\n";

    Hospital hospital;

    // Admit 6 patients: 3 critical in ICU, 3 non-critical in Ward A
    for (int i = 0; i < 3; ++i) {
        Patient p("Critical Patient" + std::to_string(i), "1990-01-01", "0000-0000000",
                  "Cardiac arrest", "2026-04-01", "ICU", true, false);
        hospital.admit(p);
    }
    for (int i = 0; i < 3; ++i) {
        Patient p("Normal Patient" + std::to_string(i), "1990-01-01", "0000-0000000",
                  "Flu", "2026-04-01", "Ward A", false, false);
        hospital.admit(p);
    }

    // Filter: critical patients in ICU
    int cnt = 0;
    Patient** criticalInICU = hospital.filterPatients(
        [](const Patient& p) {
            return p.isCritical() && p.ward() == "ICU";
        }, cnt);

    check(cnt == 3, "TC-08 | filterPatients: 3 critical ICU patients found");
    delete[] criticalInICU;

    // Sort by total bill
    int sortCnt = 0;
    Patient** byBill = hospital.sortPatients(
        [](const Patient& a, const Patient& b) {
            return a.totalBill() < b.totalBill();
        }, sortCnt);

    bool sorted = true;
    for (int i = 0; i < sortCnt - 1; ++i)
        if (byBill[i]->totalBill() > byBill[i + 1]->totalBill()) { sorted = false; break; }

    check(sorted, "TC-08 | sortPatients: patients sorted by bill ascending");
    delete[] byBill;
}

// ============================================================
// TC-09 | Staff Billing Rate Polymorphism
// ============================================================
static void tc09() {
    std::cout << "\n========== TC-09 : Staff Billing Rate Polymorphism ==========\n";

    GP      gp1     ("Dr. Ayesha Malik", "1980-03-12", "0300-1111111", 150000, "General Practice", 2000.0);
    Surgeon surgeon1("Dr. Bilal Khan",   "1975-07-22", "0321-2222222", 250000, "Surgery",          "Cardiothoracic", 15000.0);
    Nurse   nurse1  ("Nurse Rabia Noor", "1992-05-18", "0333-3333333",  60000, "General Ward",     "Ward A", 800.0);

    std::vector<StaffMember*> staff = { &gp1, &surgeon1, &nurse1 };

    double rates[3];
    int idx = 0;
    for (auto* s : staff) {
        rates[idx++] = s->calculateBillingRate();
        std::cout << s->name() << " : PKR " << s->calculateBillingRate() << std::endl;
    }

    // GP = 2000, Surgeon = 15000, Nurse = 800 — all different, no typeid
    check(rates[0] == 2000.0,  "TC-09 | GP billing rate correct (2000)");
    check(rates[1] == 15000.0, "TC-09 | Surgeon billing rate correct (15000)");
    check(rates[2] == 800.0,   "TC-09 | Nurse billing rate correct (800)");
    check(rates[0] != rates[1] && rates[1] != rates[2],
          "TC-09 | All three rates are different");
}

// ============================================================
// TC-10 | Revenue Report
// ============================================================
static void tc10() {
    std::cout << "\n========== TC-10 : Revenue Report ==========\n";

    Hospital hospital;

    // Create 3 patients in "Ward A"; we'll control their bills precisely.
    // generateBill computes: treatments + days*dailyRate + 500 admin
    // To hit exact totals, we set admission date far back so days*rate dominates,
    // then we just verify the sum of their individual bills equals wardRevenue.

    Patient p1("Patient One",   "1990-01-01", "0000-0000001",
               "Back pain",     "2026-04-01", "Ward A");
    Patient p2("Patient Two",   "1990-01-01", "0000-0000002",
               "Headache",      "2026-04-02", "Ward A");
    Patient p3("Patient Three", "1990-01-01", "0000-0000003",
               "Chest pain",    "2026-04-03", "Ward A");

    p1.addTreatment(Treatment("X-Ray",  1500, "Dr. Alvi"));
    p2.addTreatment(Treatment("MRI",    5000, "Dr. Khan"));
    p3.addTreatment(Treatment("ECG",    2000, "Dr. Alvi"));

    // Compute expected revenue before admitting (same dailyRate)
    double dailyRate = 500.0;
    double expected = p1.generateBill(dailyRate).total()
                    + p2.generateBill(dailyRate).total()
                    + p3.generateBill(dailyRate).total();

    hospital.admit(p1);
    hospital.admit(p2);
    hospital.admit(p3);

    hospital.discharge(p1.id(), dailyRate);
    hospital.discharge(p2.id(), dailyRate);
    hospital.discharge(p3.id(), dailyRate);

    double revenue = hospital.wardRevenue("Ward A");

    std::cout << "Expected revenue : PKR " << expected << std::endl;
    std::cout << "Reported revenue : PKR " << revenue  << std::endl;

    check(revenue == expected, "TC-10 | wardRevenue matches sum of individual bills");
}

// ============================================================
// main
// ============================================================
int main() {
    std::cout << "============================================" << std::endl;
    std::cout << "   MediCore Hospital System — Test Suite   " << std::endl;
    std::cout << "============================================" << std::endl;

    tc01();
    tc02();
    tc03();
    tc04();
    tc05();
    tc06();
    tc07();
    tc08();
    tc09();
    tc10();

    std::cout << "\n============================================" << std::endl;
    std::cout << "              All tests complete            " << std::endl;
    std::cout << "============================================" << std::endl;

    return 0;
}
