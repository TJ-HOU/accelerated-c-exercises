#include "Pic.h"
#include "Vec.h"
#include "Str.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main()
   {
   Vec<Str> i;
   i.push_back("Paris");
   i.push_back("in the");
   i.push_back("Spring");
   Vec<Str> j;
   j=i; 
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

   Picture s = vcat(q, r);
   cout << "s = vcat(q,r): " << endl;
   cout << s << endl;
   
   cout << "frame(hcat(s, vcat(r, q))): " << endl;
   cout << frame(hcat(s, vcat(r, q))) << endl; 
   return 0;
   }