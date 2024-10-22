#pragma once

#include <string>

class Module {
    private:
        std::string _name;
        double _ca;
        double _ct;
        double _asg;
    public:
        Module();
        Module(std::string name, double ca, double ct, double asg);

        void setName(std::string name);
        std::string getName();
        void setCa(double ca);
        double getCa();
        void setCt(double ct);
        double getCt();
        void setAsg(double asg);
        double getAsg();
        double calculateTotal();
};