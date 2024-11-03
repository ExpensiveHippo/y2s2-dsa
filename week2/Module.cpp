#include "Module.hpp"

#include <string>

Module::Module() {}
Module::Module(std::string name, double ca, double ct, double asg) : _name(name), _ca(ca), _ct(ct), _asg(asg) {}

void Module::setName(std::string name)
{
    _name = name;
}

std::string Module::getName()
{
    return _name;
}

void Module::setCa(double ca)
{
    _ca = ca;
}

double Module::getCa()
{
    return _ca;
}

void Module::setCt(double ct)
{
    _ct = ct;
}

double Module::getCt()
{
    return _ct;
}

void Module::setAsg(double asg)
{
    _asg = asg;
}

double Module::getAsg()
{
    return _asg;
}

double Module::calculateTotal()
{
    return 0.3 * _ca +
           0.3 * _ct +
           0.4 * _asg;
}
