#include"JValues.h"

string deserialize(const string& ref)
{
    string out = "";
    for(size_t i = 0; i < ref.length(); i++)
    {
        if(ref[i] == '\\' && i + 1 < ref.length())
        {
            int plus = 2;
            if(ref[i+1] == '\"')
            {
                out += '"';
            }
            else if(ref[i+1] == '\\')
            {
                out += '\\';
            }
            else if(ref[i+1] == '/')
            {
                out += '/';
            }
            else if(ref[i+1] == 'b')
            {
                out += '\b';
            }
            else if(ref[i+1] == 'f')
            {
                out += '\f';
            }
            else if(ref[i+1] == 'n')
            {
                out += '\n';
            }
            else if(ref[i+1] == 'r')
            {
                out += '\r';
            }
            else if(ref[i+1] == 't')
            {
                out += '\t';
            }
            else if(ref[i+1] == 'u' && i+5 < ref.length())
            {
                unsigned long long v = 0;
                for(int j = 0; j < 4; j++)
                {
                   v *= 16;
                    if(ref[i+2+j] <= '9' && ref[i+2+j] >= '0')
                    {
                        v += ref[i+2+j] - '0';
                    }
                    if (ref[i+2+j] <= 'f' && ref[i+2+j] >= 'a')
                    {
                            v += ref[i+2+j]-'a'+10;
                    }
                }
                out += (char)v;
                plus = 6;
            }
            i += plus - 1;
            continue;
        }
        out += ref[i];
    }
    return out;
}

string jValue::makesp(int d)
{
    string s = "";
    while(d--)
    {
        s += " ";
    }
    return s;
}

string jValue::to_string_d(int d)
{
    if(type == JSTRING)
    {
        return string("\"") + svalue + string("\"");
    }
    if(type == JNUMBER)
    {
        return svalue;
    }
    if(type == JBOOLEAN)
    {
        return svalue;
    }
    if(type == JNULL)
    {
        return "null";
    }
    if(type == JOBJECT)
    {
        string s = string("{\n");
        for(size_t i = 0; i < properties.getNumberOfElements(); i++)
        {
            s += makesp(d) + string("\"") + properties[i].first + string("\": ") + properties[i].second.to_string_d(d+1) + string(i == properties.getNumberOfElements() - 1?"":",") + string("\n");
        }
        s+= makesp(d-1) + string("}");
        return s;
    }
    if(type == JARRAY)
    {
        string s = "[";
        for(size_t i = 0; i < arr.getNumberOfElements(); i++)
        {
            if(i)
            {
                s += ", ";
                s += arr[i].to_string_d(d+1);
            }
            s += "]";
            return s;
        }
        return "##";
    }
}

jValue::jValue()
{
    this->type = JUNKNOWN;
}

jValue::jValue(jType type)
{
    this->type = type;
}

string jValue::to_string()
{
    return to_string_d(1);
}

jType jValue::getType()
{
    return type;
}

void jValue::setType(jType type)
{
    this->type = type;
}

void jValue::addProperty(string key, jValue value)
{
    mpindex[key] = properties.getNumberOfElements();
    properties.push(make_pair(key, value));
}

void jValue::addElement(jValue value)
{
    arr.push(value);
}

void jValue::setString(string s)
{
    svalue = s;
}

int jValue::asInt()
{
    stringstream ss;
    ss << svalue;
    int k;
    ss >> k;
    return k;
}

double jValue::asDouble()
{
    stringstream ss;
    ss << svalue;
    double k;
    ss >> k;
    return k;
}

bool jValue::as_bool()
{
    if(svalue == "true")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void* jValue::as_null()
{
    return NULL;
}

string jValue::asString()
{
  return deserialize(svalue);
}

int jValue::size()
{
  if (type == JARRAY)
  {
    return (int)arr.getNumberOfElements();
  }
  if (type == JOBJECT)
  {
    return (int)properties.getNumberOfElements();
  }
  return 0;
}

jValue jValue::operator[](int i)
{
  if (type == JARRAY)
  {
    return arr[i];
  }
  if (type == JOBJECT)
  {
    return properties[i].second;
  }
  return jValue();
}

jValue jValue::operator[](string s)
{
  if (mpindex.find(s) == mpindex.end())
    {
        return jValue();
    }
  return properties[mpindex[s]].second;
}
