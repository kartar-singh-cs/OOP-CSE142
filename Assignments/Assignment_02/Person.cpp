#include "Person.h"

int Person::nextId_ = 1000;

Person::Person(const std::string& name, const std::string& dob, const std::string& phone)
    : name_(name), dob_(dob), id_(nextId_++), phone_(phone) {}
