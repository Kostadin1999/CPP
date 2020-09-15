#ifndef __KOSTADIN_H__
#define __KOSTADIN_H__


#include<map>
#include<sstream>
#include<fstream>
#include<string>
#include<cstring>
#include<iostream>
#include"Vector.h"
#include"JValues.h"
using namespace std;

class Parser
    {
private:
    enum Token_Type
    {
        UNKNOWN,
        STRING,
        NUMBER,
        CROUSH_OPEN,
        CROUSH_CLOSE,
        BRACKET_OPEN,
        BRACKET_CLOSE,
        COMMA,
        COLON,
        BOOLEAN,
        NUL
    };

    struct token;
    static bool isWhitespace(const char c);
    static int nextWhitespace(string& source, int i);
    static int skipWhitespaces(string& source, int i);
    static Vector<token> tokenize(string source);
    static jValue jsonParse(Vector<token> v, int i, int& r);
public:
    static jValue parse(const string& str);
    static jValue parseFile(const string& str);
    };
//}
#endif  //__KOSTADIN_H
