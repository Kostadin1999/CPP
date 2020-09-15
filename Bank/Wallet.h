#pragma once
#include "vector.h"
#include <iostream>
#include <cstring>
#include <random>
#include <fstream>
#include <ctime>
using namespace std;

struct Wallet
{
    char name[256];
    unsigned id;
    double fiatMoney;
    Wallet();
    Wallet(const char*, double, unsigned);
    Wallet(const Wallet&);
    Wallet& operator=(const Wallet& other);
    ~Wallet();
    void copy(const Wallet& other);
    void erase();
    const char* getName() const;
	double getMoney() const;
	unsigned getId() const;
	void print() const;
	unsigned generator();
	void readInformationFromWallet(ifstream& stream);
	void writeInWallet(ofstream& stream);
	void showWalletinfo();
	double balance(double bal);
};
