#include "Pic.h"
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

int main()
   {
   vector<string> i;
   i.push_back("Paris");
   i.push_back("in the");
   i.push_back("Spring");

   // Exercise 15-1
   Picture p(i);
   cout << "Picture p: " << endl;
   cout << p << endl;

   Picture q = frame(p);
   cout << "q = frame(p): " << endl;
   cout << q << endl;

   Picture r = hcat(p, q);
   cout << "r = hcat(p,q): " << endl;
   cout << r << endl;

   Picture s = hcat(q, p);
   cout << "s = hcat(q,p): " << endl;
   cout << s << endl;

   Picture t = vcat(q, r);
   cout << "t = vcat(q,r): " << endl;
   cout << t << endl;
   
   cout << "frame(hcat(t, vcat(r, q))): " << endl;
   cout << frame(hcat(t, vcat(r, q))) << endl; 
   return 0;
   }