#pragma once

#include <string>

class Customer
{
private:
    std::string name;
    int queueNum; // the i-th minute Customer joins queue.

public:
    Customer();
    Customer(std::string n, int q);
    void setName(std::string n);
    std::string getName();
    void setQueueNum(int q);
    int getQueueNum();
};
