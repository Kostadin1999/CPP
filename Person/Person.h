#include <iostream>
using namespace std;
class Person
{
private:
    char* name;
    char ucn[11];
    bool gender;
    int age;
    void copy(const Person& other);
    void destroy();
public:
    Person();
    Person(const char* name, const char* ucn, bool gender, int age);
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();
	void changeName(const char* name);
	void incrementAge();
};
