#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include "JSON.h"
using namespace std;

int main()
{
  /*ifstream in("data.txt", ios::app);
  string str = "";
  string tmp;
  while (getline(in, tmp)) str += tmp;
  kostadin::jValue v = kostadin::Parser::parseFile(str);
  cout << v.to_string() << endl;

  cout << " ------ " << endl;
  cout << v["examples"][0]["attr"][0]["value"].asString() << endl;
  if (v["examples"][1]["mixed"][5][1][1].as_bool()) {
    cout << v["examples"][1]["pie"].asDouble() << endl;
    cout << v["examples"][2].to_string() << endl;
  }
  //cout << "Hello World" << endl;*/
  Parser p;
  jValue j;
    return 0;
}
