#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
   cout << "Q1: test constructors" << endl;
   // default, num of char constructors
   cout << string() << endl;
   cout << string(3, 'A') << endl;
   // copy constructor, assignment constructor
   string s1 = string(3, 'X');
   string s2 = string(s1);
   cout << s2 << endl;
   string s3;
   s3 = s2;
   cout << s3 << endl;
   cout << endl;

   cout << "Q2: test the c_str, data, and copy" << endl;
   // c_str(), data(), copy()
   string s6 = "Hello world!";
   char buf[80] = {0};
   const char* c_str = s6.c_str();
   const char* data = s6.data();
   s6[6] = 'W';
   cout << c_str << endl;
   cout << data << endl;
   cout << s6.copy(buf, 79) << endl;
   cout << buf << endl;
   cout << endl;

   cout << "Q3: test the relational operators" << endl;
   // relational operators
   string s7 = "A";
   string s8 = "Z";
   cout << (s7 < s8) << endl;
   cout << (s7 > s8) << endl;
   cout << (s7 <= s8) << endl;
   cout << (s7 >= s8) << endl;
   cout << endl;

   cout << "Q4: test == and != operators" << endl;
   // (in)equality operators
   cout << (s7 == s8) << endl;
   cout << (s7 != s8) << endl;
   cout << endl;

   cout << "Q5: test + operators" << endl;
   // Concatenation
   string str9 = "Hello ";
   string str10 = "World!";
   cout << (str9 + str10) << endl;
   cout << ("Hello " + str10) << endl;
   cout << (str9 + "World!") << endl;
   cout << endl;

   /* cout << "Q6: test conversion operators" << endl;
   // Str as condition
   string str11 = "";
   string str12 = "Not empty";
   if (!str11) cout << "Yes" << endl;
   if (str12) cout << "Yes" << endl;
   cout << endl; */

   cout << "Q7: test iterators" << endl;
   string s4 = "Hello";
   cout << s4 << endl;
   cout << string(s4.begin(), s4.end()) << endl;
   cout << endl;

   cout << "Q8: test getline, >>" << endl;
   string s13;
   cout << "Enter space-delimited text: ";
   getline(cin, s13);
   cout << s13 << endl;
/*    cout << "Enter space-delimited text: ";
   cin >> s13;
   cout << s13 << endl; */
   cout << endl;

   cout << "Q9: test output operator" << endl;
   string s14 = "Hello World!";
   cout << s14 << endl;
   cout << endl;

   cout << "Q12: test insert function" << endl;
   // insert()
   string s15 = "Hello !";
   string s16 = "World";
   s15.insert(s15.begin() + 6, s16.begin(), s16.end());
   cout << s15 << endl;
   cout << endl;

   return 0; 
   }
   /* cout << "Q1: test constructor" << endl;
   string s = "Hello, world!";
   cout << s << endl;
   cout << endl;
   cout << "Q2: test the c_str, data, and copy" << endl;
   cout << s.c_str() << endl;
   cout << s.data() << endl;
   char msg[6];
   s.copy(msg, 5);
   msg[5] = '\0';
   cout << msg << endl;
   cout << endl;
   cout << "Q3: test the relational operators" << endl;
   string s1 = "a";
   string s2 = "b";
   string s3 = "c";
   cout << "s1 is " << (s1 > s2 ? "larger" : "smaller") << " than s2" << endl;
   cout << "s3 is " << (s3 < s1 ? "smaller" : "larger") << " than s1" << endl;
   cout << endl;
   cout << "Q4: test == and != operators" << endl;
   string s4 = "Hello, world!";
   string s5 = "Goodbye, world!";
   string s6 = "Hello, world!";
   cout << "s1 and s2 are " << (s4 == s5 ? "equal" : "not equal") << endl;
   cout << "s1 and s3 are " << (s4 == s6 ? "equal" : "not equal") << endl;
   cout << endl;
   cout << "Q5: test + operators" << endl;
   string s7 = "Hello,";
   cout << s7 + " world!" << endl;
   cout << endl;
   cout << "Q6: test conversion operators" << endl;
   string s8;
   //cout << "s is " << (s ? "not empty" : "empty") << endl;
   //cout << "s8 is " << (s8 ? "not empty" : "empty") << endl;
   cout << endl;
   cout << "Q7: test iterators" << endl;
   for (auto it = s.begin(); it != s.end(); it++)
      {
      cout << *it;
      }  
   cout << endl;
   cout << endl;
   cout << "Q8: test getline functions" << endl;
   string t;
   getline(cin, t);
   cout << t << endl;
   cout << endl;
   cout << "Q9: test output operator" << endl;
   cout << s << endl;
   cout << endl;
   cout << "Q12: test insert function" << endl;
   s4.insert(s4.begin() + 7, s5.begin(), s5.end());
   cout << s4 << endl;
   cout << endl;
   return 0;  
   }*/