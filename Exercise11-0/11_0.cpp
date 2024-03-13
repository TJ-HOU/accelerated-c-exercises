#include "vec.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
   {
   Vec<string> v1(1,"abc");
   string s;
   while (getline(cin, s)) 
      v1.push_back(s);
   cout << "v1 elements: " << endl;
   for (Vec<string>::size_type i = 0; i != v1.size(); ++i)
      {
      cout << v1[i] << endl;
      }
   cout << "v1 size: " << v1.size() << endl; 
   Vec<string> v2 = v1;
   v2.erase(v2.begin());
   cout << "v2 size: " << v2.size() << endl;
   cout << "v2 elements: " << endl;
   for (Vec<string>::size_type i = 0; i != v2.size(); ++i)
      {
      cout << v2[i] << endl;
      }  
   v1.clear();
   v2.clear();
   cout << "after clear v1 size: " << v1.size() << endl;
   cout << "after clear v2 size: " << v2.size() << endl;
   return 0;
   }