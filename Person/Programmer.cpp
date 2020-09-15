 #include"Programmer.h"

 Programmer::Programmer() : Person()
    {
        strcpy(this->employer,"");
        this->salary = 0;
        this->workingHours = 0;
    }

    Programmer::Programmer(const char* name, const char* ucn, bool gender, int age, const char* employer, double salary, int workingHours) : Person(name, ucn, gender, age)
    {
        strcpy(this->employer,employer);
        this->salary = salary;
        this->workingHours = workingHours;
    }

    friend ostream& operator<<(ostream& os, const Programmer& programmer)
    {
        os << (Person)programmer;
        os << programmer.employer << endl;
        os << programmer.salary << endl;
        os << programmer.workingHours << endl;

        return os;
    }

    friend istream& operator>>(istream& is, Programmer& programmer)
	{
		is >> (Person&)programmer;
		is >> programmer.employer;
		is >> programmer.salary;
		is >> programmer.workingHours;

		return is;
	}
