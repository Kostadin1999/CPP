#pragma once
#include "vector.h"
#include<iostream>
#include<fstream>
#include "EnumType.h"
using namespace std;

struct Order
{
    Type type;
    unsigned walletId;
    double fmiCoins;
    void copy(const Order& other);
    void erase();
    Order();
    Order(Type type, unsigned walletId, double fmiCoins);
    Order(const Order& other);
    Order& operator=(const Order& other);
    ~Order();
    unsigned getWalletId() const;
    double getFmiCoins() const;
    Type getType() const;
    void readInformationFromOrder(ifstream& stream);
    void writeInOrder(ofstream& stream);
};
