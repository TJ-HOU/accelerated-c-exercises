#include "Str.h"
#include "vec.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
   {
   char input[] = "Hello, World!";
   Str v1 = Str(input);
   cout << "v1 size: " << v1.size() << endl;
   cout << "v1 elements: " << endl;
   for (Str::size_type i = 0; i != v1.size(); ++i)
      {
      cout << v1[i];
      }
   cout << endl;
   Str v2 = v1 + v1;
   cout << "v2 size: " << v2.size() << endl;
   cout << "v2 elements: " << endl;
   for (Str::size_type i = 0; i != v2.size(); ++i)
      {
      cout << v2[i];
      } 
   cout << endl; 
   return 0;
   }