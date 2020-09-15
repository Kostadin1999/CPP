#pragma once
#include<iostream>
#include<cstring>

using namespace std;

class Person
{
private:
    char* personName;
    size_t insuranceId;
    void copy(const Person& other);
    void erase();
public:
    Person();
    Person(const char* personName, size_t insuranceId);
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();
    const char* getPersonName() const;
    size_t getInsuranceId() const;
};
