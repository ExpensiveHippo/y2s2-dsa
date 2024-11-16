#include "Customer.hpp"

Customer::Customer() {}

Customer::Customer(std::string n, int qNum) : name(n), queueNum(qNum) {}

void Customer::setName(std::string n) { name = n; }

std::string Customer::getName() { return name; }

void Customer::setQueueNum(int q) { queueNum = q; }

int Customer::getQueueNum() { return queueNum; }
