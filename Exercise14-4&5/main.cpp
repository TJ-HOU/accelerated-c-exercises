#include "Str.h"
#include "split.h"
#include "frame.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::cin;
using std::ostream_iterator;
using std::copy;

int main()
   {
   Str str = "split the string";
   Vec<Str> ret = split(str);
   cout << "Split: " << endl;
   for (auto it = ret.begin(); it != ret.end(); ++it)
      {
      cout << *it << endl;
      }
   cout << endl;

   Vec<Str> v;
   v.push_back("this is an");
   v.push_back("example");
   v.push_back("to");
   v.push_back("illustrate");
   v.push_back("framing"); 

   Vec<Str> result;
   result = frame(v);
   cout << "Frame: " << endl;
   for (auto i = 0; i != result.size(); ++i)
      {
      cout << result[i] << endl;
      }
   cout << endl;

   cout << "Vertical Frame: " << endl;
   Vec<Str> vresult;
   vresult = vcat(v,result);
   for (auto i = 0; i != vresult.size(); ++i)
      {
      cout << vresult[i] << endl;
      }
   cout << endl;

   cout << "Horizontal Frame: " << endl;
   Vec<Str> hresult;
   hresult = hcat(v,result);
   for (auto i = 0; i != hresult.size(); ++i)
      {
      cout << hresult[i] << endl;
      }
   cout << endl;

   return 0;   
   }
