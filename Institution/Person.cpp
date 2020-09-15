#include"Person.h"

void Person::copy(const Person& other)
{
    this->personName = new char[strlen(other.personName) + 1];
    strcpy(this->personName, other.personName);
    this->insuranceId = other.insuranceId;
}

void Person::erase()
{
    delete [] this->personName;
}

Person::Person()
{
    this->personName = new char[1];
    strcpy(this->personName, "");
    this->insuranceId = 1;
}

Person::Person(const char* name, size_t id)
{
    this->personName = new char[strlen(name) + 1];
    strcpy(this->personName, name);
    this->insuranceId = id;
}

Person::Person(const Person& other)
{
    this->copy(other);
}

Person& Person::operator=(const Person& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Person::~Person()
{
    this->erase();
}

const char* Person::getPersonName() const
{
    return this->personName;
}

size_t Person::getInsuranceId() const
{
    return this->insuranceId;
}
