#include<iostream>
#include"Person.h"
using namespace std;

class Programmer : public Person
{
private:
    char employer[64];
    double salary;
    int workingHours;
public:
    Programmer();
    Programmer(const char* name, const char* ucn, bool gender, int age, const char* employer, double salary, int workingHours)
};
