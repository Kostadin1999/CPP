#pragma once
#include<iostream>
#include<cstring>
#include"Person.h"

using namespace std;

class Institution
{
private:
    size_t institutionId;
    char* institutionName;
    void copy(const Institution& other);
    void erase();
public:
    Institution();
    Institution( const char* institutionName, size_t institutionId);
    Institution(const Institution& other);
    Institution& operator=(const Institution& other);
    ~Institution();
    size_t getInstitutionId() const;
    const char* getInstitutionName() const;
    void hasMember(const Person& person);
    bool isValidInstitution();
};
