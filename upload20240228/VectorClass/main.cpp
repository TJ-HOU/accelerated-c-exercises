/*
11-6 Add erase and clear operations to Vec class.
12-10 Define a constructor that takes a pair of iterators.
12-12 Define the insert function that takes 2 iterators.
12-13 Provide an assign function that could be used to assign the values in an array to a Vec. 
12-14 Write a program to initialize a Vec from a string.
*/
#include "Vec.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void print_vec(const Vec<char>& v) 
   {
   for (size_t i = 0; i != v.size(); ++i) 
      {
      cout << v[i];
      }
   }

int main()
   { 
   // 12-10
   // Test iterators constructor
   char a0[] = "123";
   Vec<char> v0(a0, a0 + 3);
   cout << "Exercise 12-10: " << endl;
   cout << "Test iterators constructor: " << endl;
   print_vec(v0);
   cout << endl << endl;
     
   // 12-12
   // Test insert
   char a1[] = "1256";
   char a2[] = "34";
   Vec<char> v1(a1, a1 + 4);
   Vec<char> v2(a2, a2 + 2);
   v1.insert(v1.begin() + 2, v2.begin(), v2.end());
   cout << "Exercise 12-12: " << endl;
   cout << "Test insert: " << endl;
   print_vec(v1);
   cout << endl << endl;
   
   // 12-13
   // Test assign
   char a3[] = "123";
   char a4[] = "456";
   Vec<char> v3(a3, a3 + 3);
   Vec<char> v4(a4, a4 + 3);
   v3.assign(v4.begin(), v4.end());
   cout << "Exercise 12-13: " << endl;
   cout << "Test assign: " << endl;
   print_vec(v3);
   cout << endl << endl;

   // 12-14
   // Test initializing from a string
   string s = "123456";
   Vec<char> v5(s.begin(), s.end());
   cout << "Exercise 12-14: " << endl;
   cout << "Test initializing from a string: " << endl;
   print_vec(v5);
   cout << endl << endl;

   // 11-6
   // Test erase
   cout << "Exercise 11-6: " << endl;
   cout << "Test erase: " << endl;
   cout << "v0 size: " << v0.size() << endl;
   v0.erase(v0.begin());
   cout << "v0 size after erase the 1st element: " << v0.size() << endl;
   print_vec(v0); 
   cout << endl << endl;

   // Test clear 
   v0.clear();
   cout << "Test clear: " << endl;
   cout << "after clear v0 size: " << v0.size() << endl;
   print_vec(v0);
   cout << endl; 
 
   return 0;
   }