#include"Student.h"

 void Student::copy(const Student& other)
    {
        this->fn = new char[strlen(other.fn) + 1];
        strcpy_s(this->fn, strlen(other.fn) + 1, other.fn);
        this->gpa = gpa;
    }

    void Student::destroy()
    {
        delete[] this->fn;
    }

    Student::Student() : Person()
    {
		this->fn = new char[1];
		strcpy_s(this->fn, 1, "");
		this->gpa = 0.0;
	}

	Student::Student(const char* name, const char* ucn, bool gender, int age, const char* fn, double gpa) : Person(name, ucn, gender, age)
	{
		this->fn = new char[strlen(fn) + 1];
		strcpy_s(this->fn, strlen(fn) + 1, fn);
		this->gpa = gpa;
	}

	Student::Student(const Student& other) : Person(other)
	{
		this->copy(other);
	}

	Student::Student& operator=(const Student& other)
	{
		if (this != &other)
		{
			Person::operator=(other);
			this->destroy();
			this->copy(other);
		}
		return *this;
	}

	Student::~Student()
	{
		this->destroy();
	}

    friend ostream& operator<<(ostream& os, const Student& student)
    {
        os << (Person)student;
        os << student.fn << endl;
        os << student.gpa << endl;

        return os;
    }

    friend istream& operator>>(istream& is, Student& student)
    {
        is >> (Person&)student;
        is >> student.fn;
        is >> student.gpa;

        return is;
    }
