/*
10-4. Write a class that implements a list that holds strings
10-5. Write a bidirectional iterator for your String_list class.
10-6. Test the class by rewriting the split function to put its output into a String_list.
*/
#include <iostream>
using std::cout;
using std::endl;
#include "String_list.h"
#include "split.h"

void print_strlist(const String_list& str_list) 
   {
   auto iter = str_list.begin();
   while (iter != str_list.end())
      {
      cout << *iter++ << endl;
      }
   cout << endl;
   }

int main() 
   {
   // 10-4
   // Test push_back
   cout << "Exercise 10-4: " << endl;
   cout << "Test push_back: " << endl;
   String_list list1;
   list1.push_back("the");
   list1.push_back("first");
   list1.push_back("string");
   list1.push_back("list");
   print_strlist(list1);

   // Test reverse
   cout << "Test reverse: " << endl;
   print_strlist(list1.reverse());

   // Test append
   String_list list2;
   list2.push_back("add");
   list2.push_back("another");
   list2.push_back("string");
   list2.push_back("list");
   cout << "Test append: " << endl;
   print_strlist(list1.append(list2));

   // 10-5
   cout << "Exercise 10-5: " << endl;
   string arr1[] = {"Hello", "to", "the", "world!"};
   String_list a = String_list(arr1, arr1 + 4);
   String_list::const_iterator i = a.begin();

   cout << "Test == and != operators" << endl;
   // (in)equality operators
   if (a.begin() == a.begin())
   cout << "The beginning" << endl; // Should print "The beginning"
   if (a.begin() != a.end())
   cout << "Is not the end" << endl; // Should print "Is not the end"
   cout << endl;

   cout << "Test dereference: " << endl;
   // Test dereference
   cout << *i << endl; // Should print "Hello"
   cout << i->size() << endl; // Should print 5, from "Hello"
   cout << endl;

   cout << "Test increment/decrement: " << endl;
   // Test increment
   ++i;
   cout << *i << endl; // Should print "to"
   i++;
   cout << *i << endl; // Should print "the"
   cout << *i++ << endl; // Should print "the"
   cout << *i << endl; // Should print "world!"

   // Test decrement
   --i;
   cout << *i << endl; // Should print "the"
   i--;
   cout << *i << endl; // Should print "to"
   cout << *i-- << endl; // Should print "to"
   cout << *i << endl; // Should print "Hello"
   

   // 10-6
   // Test split
   cout << "Exercise 10-6: " << endl;
   cout << "Test split: " << endl;
   String_list list3 = split("Hello to the World!");
   print_strlist(list3);
   
   return 0;
   }