#pragma once
#include <string>

class Person {
protected:
    std::string name_;
    std::string dob_;
    int id_;
    std::string phone_;
    static int nextId_;

public:
    Person(const std::string& name, const std::string& dob, const std::string& phone);
    virtual ~Person() = default;

    virtual void display() const = 0;

    const std::string& name() const { return name_; }
    const std::string& dob()  const { return dob_; }
    int id()                  const { return id_; }
    const std::string& phone() const { return phone_; }
};
