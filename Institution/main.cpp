#include <iostream>
#include"Payer.h"
#include"Person.h"
#include"Institution.h"
#include"Group.h"
#include"Organization.h"
using namespace std;

int main()
{
    Person person("George", 46);
    Institution ins("Sarai", 46);
    ins.hasMember(person);
    ins.isValidInstitution();
    Group gr;
    Payer p("ivan", 22, "geshev");
    Organization g;
    gr.isInGroup(person);
    Organization org;
    g.numOfAssociatedGroups(p);
    gr.isInGroup(person);
}
