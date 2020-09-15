#include"Person.h"
#include"Payer.h"

void Payer::copy(const Payer& other)
{
    this->payerName = new char[strlen(other.payerName) + 1];
    strcpy(this->payerName, other.payerName);
}

void Payer::erase()
{
    delete [] this->payerName;
}

Payer::Payer() : Person()
{
    this->payerName = new char[1];
    strcpy(this->payerName, "");

}

Payer::Payer(const char* personName, size_t insuranceId, const char* payerName) : Person(personName, insuranceId)
{
    this->payerName = new char[strlen(payerName) + 1];
    strcpy(this->payerName, payerName);
}

Payer::Payer(const Payer& other) : Person(other)
{
    this->copy(other);
}

Payer& Payer::operator=(const Payer& other)
{
    if(this != &other)
    {
        Person::operator=(other);
        this->erase();
        this->copy(other);
    }
    return *this;
}

Payer::~Payer()
{
    this->erase();
}

const char* Payer::getPayerName() const
{
    return this->payerName;
}
