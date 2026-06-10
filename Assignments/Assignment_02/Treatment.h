#pragma once
#include <string>

class Treatment {
    std::string name_;
    double cost_;
    std::string staffName_;

public:
    Treatment(const std::string& name, double cost, const std::string& staffName);

    const std::string& name()      const { return name_; }
    double             cost()      const { return cost_; }
    const std::string& staffName() const { return staffName_; }
};
