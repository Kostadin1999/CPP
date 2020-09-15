#include"Group.h"
#include"Payer.h"

Group::Group() : Institution()
{
    this->groupId = 1;
    this->groupPayer = Payer();
}

Group::Group(const char* institutionName, size_t institutionId, unsigned int groupId, Payer groupPayer) : Institution(institutionName, institutionId)
{
    this->groupId = groupId;
    this->groupPayer = groupPayer;
}

/*size_t Group::getNumOfPayers()const
{
    return this->numOfPayers;
}*/

unsigned int Group::getGroupId() const
{
    return this->groupId;
}


bool Group::isValidGroup(Payer payer)
{
    //Group group;
    if(groupId == payer.getInsuranceId())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Group::isInGroup(Person per)
{
    if(per.getInsuranceId() == groupId)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Group::setGroupPayer(Payer payer)
{
    this->groupPayer = groupPayer;
}

void Group::mainPayer(Payer p)
{
    if(isValidGroup(p))
    {
        setGroupPayer(p);
    }
}
