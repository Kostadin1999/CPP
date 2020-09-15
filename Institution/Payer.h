#pragma once
#include<iostream>
#include<cstring>
#include"Person.h"
//#include"Group.h"
using namespace std;

class Payer : public Person
{
private:
    char* payerName;
    void copy(const Payer& other);
    void erase();
public:
    Payer();
    Payer( const char* personName, size_t insuranceId, const char* payerName);
    Payer(const Payer& other);
    Payer& operator=(const Payer& other);
    ~Payer();
    const char* getPayerName() const;
};
