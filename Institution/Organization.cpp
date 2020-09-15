#include"Organization.h"

void Organization::copy(const Organization& other)
{
    for(size_t i = 0; i < numOfInstitutions; i++)
    {
        this->institutions[i] = other.institutions[i];
    }
    for(size_t i = 0; i < numOfPayers; i++)
    {
        this->payers[i] = other.payers[i];
    }
     for(size_t i = 0; i < numOfGroups; i++)
    {
        this->groups[i] = other.groups[i];
    }
    this->numOfInstitutions = other.numOfInstitutions;
    this->capacity = other.capacity;
    this->numOfPayers = other.numOfPayers;
    this->numOfGroups = other.numOfGroups;
    this->organizationAddress = new char[strlen(other.organizationAddress) + 1];
    strcpy(this->organizationAddress, other.organizationAddress);
}

void Organization::erase()
{
    delete [] this->organizationAddress;
}

void Organization::resize()
{
        this->capacity *= 2;
        Institution* temp = new Institution[this->capacity];
        for(size_t i = 0; i < numOfInstitutions; i++)
        {
            temp[i] = this->institutions[i];
        }
        this->erase();
        this->institutions = temp;
}

Organization::Organization() : Institution()
{
    this->numOfInstitutions = 0;
    this->capacity = 8;
    this->institutions = new Institution[this->capacity];
    this->groups = new Group[this->capacity];
    this->payers = new Payer[this->capacity];
    this->numOfGroups = 0;
    this->numOfPayers = 0;
    this->organizationAddress = new char[1];
    strcpy(this->organizationAddress, "");
}

Organization::Organization(const char* institutionName, size_t institutionId, Institution* institutions, Payer* payers,Group* groups, size_t numOfInstitutions, size_t numOfGroups, size_t numOfPayers,  size_t capacity, const char* organizationAddress) : Institution(institutionName, institutionId)
{
     for(size_t i = 0; i < numOfInstitutions; i++)
    {
        this->institutions[i] = institutions[i];
    }
     for(size_t i = 0; i < numOfPayers; i++)
    {
        this->payers[i] = payers[i];
    }
     for(size_t i = 0; i < numOfGroups; i++)
    {
        this->groups[i] = groups[i];
    }
    this->numOfInstitutions = numOfInstitutions;
    this->capacity = capacity;
    this->numOfPayers = numOfPayers;
    this->numOfGroups = numOfGroups;
    this->organizationAddress = new char[strlen(organizationAddress) + 1];
    strcpy(this->organizationAddress, organizationAddress);
}

Organization::Organization(const Organization& other)
{
    this->copy(other);
}

Organization& Organization::operator=(const Organization& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Organization::~Organization()
{
    this->erase();
}

size_t Organization::getNumOfInstitutions() const
{
    return this->numOfInstitutions;
}

 const char* Organization::getOrganizationAddress() const
 {
     return this->organizationAddress;
 }

 size_t Organization::getNumOfPayers() const
 {
     return this->numOfPayers;
 }

 size_t Organization::getNumOfGroups() const
 {
     return this->numOfGroups;
 }

 int Organization::numOfAssociatedGroups(Payer payer)
 {
     size_t numOfPayersGroups = 0;
     for(size_t i = 0; i < numOfGroups; i++)
     {
         if(payer.getInsuranceId() == groups[i].getGroupId())
         {
             groups[i].setGroupPayer(payer);
             numOfPayersGroups++;
         }
     }
     return numOfPayersGroups;
 }

 Payer Organization::setOrgMainPayer(Payer& payer)
 {
     this->payers = payers;
 }
 int Organization::mainPayerOrg()
 {
     for(size_t i = 0; i < numOfPayers; i++)
     {
         for(size_t j = 1; j < numOfPayers; j++)
         {
             if(numOfAssociatedGroups(payers[i]) > numOfAssociatedGroups(payers[j]))
             {
                  cout << "The is the main payer: " << endl;
                  setOrgMainPayer(payers[i]);
             }
         }
     }
 }

 void Organization::InvalidOrganization(Organization organization)
 {
     if(organization.getNumOfGroups() == 0)
     {
         cout << "The organization is invalid." << endl;
     }
     else
     {
         cout << "The organization is valid." << endl;
     }
 }

 bool Organization::isInOrganization(Person prsn)
 {
     for(size_t i = 0; i < numOfGroups; i++)
     {
         if(prsn.getInsuranceId() == groups[i].getGroupId())
         {
             return true;
         }
         else
         {
             return false;
         }
     }
 }

 void Organization::addInstitution( Institution inst)
 {
    if(inst.isValidInstitution())
    {
        if(numOfInstitutions >= capacity)
          {
             resize();
          }
         this->institutions[numOfInstitutions++] = inst;
    }

 }

 void Organization::compatibleOrganizations(Organization org, Organization org1)
 {
     if(org.mainPayerOrg() == org1.mainPayerOrg())
     {
         cout << "The organizations are compatible." << endl;
     }
     else
     {
         cout << "The organizations are not compatible." << endl;
     }
 }
