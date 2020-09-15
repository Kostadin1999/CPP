#include "Transaction.h"

long long Transaction::getTime() const
{
    return this->Time;
}

unsigned Transaction::getSenderId() const
{
    return this->senderId;
}

unsigned Transaction::getReceiverId() const
{
    return this->receiverId;
}

double Transaction::getFmiCoins() const
{
    return this->fmiCoins;
}
void Transaction::copy(const Transaction& other)
{
    this->senderId = senderId;
    this->receiverId = receiverId;
    this->fmiCoins = fmiCoins;
}
void Transaction::erase()
{
    this->senderId = 0;
    this->receiverId = 0;
    this->fmiCoins = 0;
}
Transaction::Transaction()
{
    this->senderId = 0;
    this->receiverId = 0;
    this->fmiCoins = 0;
}
Transaction::Transaction(const Transaction& other)
{
    this->copy(other);
}
Transaction& Transaction::operator=(const Transaction& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}
Transaction::~Transaction()
{
    this->erase();
}
void Transaction::readInformationFromTransaction(ifstream& stream)
{
     if(!stream)
    {
        return;
    }
    char memory[sizeof(Time) + sizeof(senderId) + sizeof(receiverId) + sizeof(fmiCoins)];
    stream.read((char*)&memory,sizeof(Time) + sizeof(senderId) + sizeof(receiverId) + sizeof(fmiCoins));
}

void Transaction::writeInTransaction(ofstream& stream)
{
    if(!stream)
    {
        return;
    }
    stream.write((const char*)&Time, sizeof(Time));
    stream.write((const char*)&senderId, sizeof(senderId));
    stream.write((const char*)&receiverId, sizeof(receiverId));
    stream.write((const char*)&fmiCoins, sizeof(fmiCoins));
}

void Transaction::setTime(const Transaction& other)
{
    {
        time_t transactionTime = other.Time;
        struct tm* timeInfo;
        time(&transactionTime);
        timeInfo = localtime(&transactionTime);
        cout<< "->Time: " << timeInfo->tm_mday<<"."<<timeInfo->tm_mon<<"."<<timeInfo->tm_year+1900<<endl;
    }
}
