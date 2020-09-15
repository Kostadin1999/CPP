#include"Institution.h"

void Institution::copy(const Institution& other)
{
    this->institutionName = new char[strlen(other.institutionName) + 1];
    strcpy(this->institutionName, other.institutionName);
    this->institutionId = other.institutionId;
}

void Institution::erase()
{
    delete [] this->institutionName;
}

Institution::Institution()
{
    this->institutionName = new char[1];
    strcpy(this->institutionName, " ");
    this->institutionId = 1;
}

Institution::Institution(const char* name, size_t id)
{
    this->institutionName = new char[strlen(institutionName) + 1];
    strcpy(this->institutionName, name);
    this->institutionId = id;
}

Institution::Institution(const Institution& other)
{
    this->copy(other);
}

Institution& Institution::operator=(const Institution& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Institution::~Institution()
{
    this->erase();
}

const char* Institution::getInstitutionName() const
{
    return this->institutionName;
}

size_t Institution::getInstitutionId() const
{
    return this->institutionId;
}

void Institution::hasMember(const Person& person)
{
    if(person.getInsuranceId() == institutionId)
    {
        cout << "Has member";
    }
    else if(person.getInsuranceId() != institutionId)
    {
       cout << "NO";
    }
}

bool Institution::isValidInstitution()
{
    if(institutionId <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

