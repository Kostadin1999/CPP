#pragma once
#include<iostream>
#include<cstring>
#include"Payer.h"
#include"Institution.h"
#include"Person.h"
using namespace std;

class Group : public Institution
{
private:
    unsigned int groupId;
    Payer groupPayer;

public:
    Group();
    Group(const char* institutionName, size_t institutionId, unsigned int groupId, Payer groupPayer);
    unsigned int getGroupId()const;
    void addPayer(const Payer& payer);
    bool isValidGroup(Payer payer);
    void mainPayer(Payer p);
    bool isInGroup(Person per);
    void setGroupPayer(Payer payer);
};
