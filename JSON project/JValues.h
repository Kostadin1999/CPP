#include<map>
#include<sstream>
#include<fstream>
#include<string>
#include<cstring>
#include<iostream>
#include"Vector.h"
using namespace std;

 enum jType{
       JSTRING,
       JOBJECT,
       JARRAY,
       JBOOLEAN,
       JNUMBER,
       JNULL,
       JUNKNOWN};

class jValue
    {
  private:
    string makesp(int);
    string svalue;
    jType type;
    Vector<pair<string, jValue>> properties;
    map<string, size_t> mpindex;
    Vector<jValue> arr;
    string to_string_d(int);
  public:
    jValue();
    jValue(jType);
    string to_string();
    jType getType();
    void setType(jType);
    void addProperty(string key, jValue value);
    void addElement(jValue v);
    void setString(string s);
    int asInt();
    double asDouble();
    bool as_bool();
    void* as_null();
    string asString();
    int size();
    jValue operator[](int i);
    jValue operator[](string s);
    };
