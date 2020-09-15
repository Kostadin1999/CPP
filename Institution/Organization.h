#pragma once
#include<iostream>
#include<cstring>
#include"Institution.h"
#include"Payer.h"
#include"Group.h"
#include<vector>
using namespace std;

class Organization : public Institution
{
private:
    Institution* institutions;
    size_t numOfInstitutions;
    size_t capacity;
    char* organizationAddress;
    Payer* payers;
    Group* groups;
    size_t numOfPayers;
    size_t numOfGroups;
    void copy(const Organization& other);
    void erase();
    void resize();
public:
    Organization();
    Organization(const char* institutionName, size_t institutionId, Institution* institutions, Payer* payers, Group* groups,
                 size_t numOfInstitutions,size_t numOfGroups, size_t numOfPayers, size_t capacity, const char* organizationAddress);
    Organization(const Organization& other);
    Organization& operator=(const Organization& other);
    ~Organization();
    size_t getNumOfInstitutions() const;
    size_t getNumOfPayers() const;
    const char* getOrganizationAddress() const;
    size_t getNumOfGroups() const;
    int mainPayerOrg();
    void compatibleOrganizations(Organization org, Organization org1);
    void InvalidOrganization(Organization organization);
    bool isInOrganization(Person prsn);
    int numOfAssociatedGroups(Payer payer);
    Payer setOrgMainPayer(Payer& payer);

	void addInstitution( Institution inst);
};

