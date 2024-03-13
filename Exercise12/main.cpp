// Chapter 12: Create the Str class
#include <iostream>
#include "Str.h"

using std::cin;
using std::cout;
using std::endl;

int main()
   {
   cout << "Q1: test constructors" << endl;
   // default, num of char constructors
   cout << Str() << endl;
   cout << Str(3, 'A') << endl;
   // copy constructor, assignment constructor
   Str s1 = Str(3, 'X');
   Str s2 = Str(s1);
   cout << s2 << endl;
   Str s3;
   s3 = s2;
   cout << s3 << endl;
   cout << endl;

   cout << "Q2: test the c_str, data, and copy" << endl;
   // c_str(), data(), copy()
   Str s4 = "Hello world!";
   char buf[80] = {0};
   const char* c_str = s4.c_str();
   const char* data = s4.data();
   s4[6] = 'W';
   cout << c_str << endl;
   cout << data << endl;
   cout << s4.copy(buf, 79) << endl;
   cout << buf << endl;
   cout << endl;

   cout << "Q3: test the relational operators" << endl;
   // relational operators
   Str s5 = "A";
   Str s6 = "Z";
   cout << (s5 < s6) << endl;
   cout << (s5 > s6) << endl;
   cout << (s5 <= s6) << endl;
   cout << (s5 >= s6) << endl;
   cout << endl;

   cout << "Q4: test == and != operators" << endl;
   // (in)equality operators
   cout << (s5 == s6) << endl;
   cout << (s5 != s6) << endl;
   cout << endl;

   cout << "Q5: test + operators" << endl;
   // Concatenation
   Str s7 = "Hello ";
   Str s8 = "World!";
   cout << (s7 + s8) << endl;
   cout << ("Hello " + s8) << endl;
   cout << (s7 + "World!") << endl;
   cout << endl;

   cout << "Q6: test conversion operators" << endl;
   // Str as condition
   Str s9 = "";
   Str s10 = "Not empty";
   if (!s9) cout << "Yes" << endl;
   if (s10) cout << "Yes" << endl;
   cout << endl;

   cout << "Q7: test iterators" << endl;
   Str s11 = "Hello, World!";
   cout << s11 << endl;
   cout << Str(s11.begin(), s11.end()) << endl;
   cout << endl;

   cout << "Q8: test getline, >>" << endl;
   Str s12;
   cout << "Enter space-delimited text: ";
   getline(cin, s12);
   cout << s12 << endl;
   cout << "Enter space-delimited text: ";
   cin >> s12;
   cout << s12 << endl; 
   cout << endl;

   cout << "Q9: test output operator" << endl;
   Str s13 = "Hello World!";
   cout << s13 << endl;
   cout << endl;

   cout << "Q12: test insert function" << endl;
   // insert()
   Str s14 = "Hello !";
   Str s15 = "World";
   s14.insert(s14.begin() + 6, s15.begin(), s15.end());
   cout << s14 << endl;
   cout << endl;

   return 0; 
   }