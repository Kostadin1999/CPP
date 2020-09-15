void Person::copy(const Person& other)
    {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name,strlen(other.name + 1),other.name);
        strcpy(this->ucn,other.ucn);
        this->gender = other.gender;
        this->age = other.age;
    }
    void destroy()
    {
        delete[] this->name;
    }

    Person::Person()
    {
        this->name = new char[1];
		strcpy_s(this->name,1, "");
		strcpy(this->ucn, "999999999999");
		this->gender = true;
		this->age = 18;
    }

    Person::Person(const char* name, const char* ucn, bool gender, int age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name,strlen(name)+1, name);
		strcpy(this->ucn, ucn);
		this->gender = gender;
		this->age = age;
	}
	Person::Person(const Person& other)
	{
		this->copy(other);
	}
	Person& Person::operator=(const Person& other)
	{
		if (this != &other)
		{
			this->destroy();
			this->copy(other);
		}
		return *this;
	}

	Person::~Person()
	{
		this->destroy();
	}

	void Person::changeName(const char* name)
	{
	    delete[] this->name;
	    this->name = new char[strlen(name)+1];
	    strcpy(this->name,name);
	}

	void Person::incrementAge()
	{
	    this->age++;
	}

	friend ostream& operator<<(ostream& os,const Person& person)
	{
	    os << person.name << endl;
	    os << person.ocn << endl;
	    os << person.age << endl;
	    os << person.gender << endl;

	    return os;
	}

	friend istream& operator>>(istream& is,Person& person)
	{
	    is >> person.name;
	    is >> person.ocn;
	    is >> person.age;
	    is >> person.gender;

	    return is;
	}
