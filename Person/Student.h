#include<iostream>
#include"Person.h"
using namespace std;

class Student : public Person
{
private:
    char* fn;
    double gpa;
    void copy(const Student& other);
    void destroy();
public:
    Student();
	Student(const char* name, const char* ucn, bool gender, int age, const char* fn, double gpa);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();
};
