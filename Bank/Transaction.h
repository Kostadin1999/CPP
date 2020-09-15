#pragma once
#include "vector.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

struct Transaction
{
    long long Time;
    unsigned senderId;
    unsigned receiverId;
    double fmiCoins;
    Transaction();
    Transaction(long long, unsigned, unsigned, double);
    Transaction(const Transaction& other);
    Transaction& operator=(const Transaction& other);
    ~Transaction();
    void copy(const Transaction& other);
    void erase();
    long long getTime() const;
    unsigned getSenderId() const;
    unsigned getReceiverId() const;
    double getFmiCoins() const;
    void readInformationFromTransaction(ifstream& stream);
    void writeInTransaction(ofstream& stream);
    void setTime(const Transaction& other);
};
