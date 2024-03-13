/* 
11-8. Write a simplified version of the standard list class and its associated iterator
10-4. Write a class that implements a list that holds strings.
10-5. Write a bidirectional iterator for your String_list class.
10-6. Test the class by rewriting the split function to put its output into a String_list.
*/
#include <iostream>
using std::cout;
using std::endl;
#include "llist.h"
#include "split.h"

int main() 
   {
   // 10-4
   // Test push_back
   cout << "Exercise 10-4: " << endl;
   cout << "Test push_back: " << endl;
   Linkedlist list1;
   list1.appendNode("the");
   list1.appendNode("first");
   list1.appendNode("string");
   list1.appendNode("list");
   list1.printList();

   // Test reverse
   cout << "Test reverse: " << endl;
   list1.reverse();
   list1.printList();

   // Test append
   Linkedlist list2;
   list2.appendNode("add");
   list2.appendNode("another");
   list2.appendNode("string");
   list2.appendNode("list");
   cout << "Test append: " << endl;
   list1.append(list2);
   list1.printList();

   // 10-5
   cout << "Exercise 10-5: " << endl;
   Linkedlist list3;
   list3.appendNode("one");
   list3.appendNode("two");
   list3.appendNode("three");
   list3.appendNode("four");
   NodeItr i = list3.begin();

   // (in)equality operators
   cout << "Test == and != operators" << endl;
   if (list3.begin() == list3.begin())
   cout << "The beginning" << endl; // Should print "The beginning"
   if (list3.begin() != list3.end())
   cout << "Is not the end" << endl; // Should print "Is not the end"
   cout << endl;

   // Test dereference
   cout << "Test dereference: " << endl;
   cout << (*i)->data << endl; // Should print "one"
   cout << ((*i)->data).size() << endl; // Should print 3, from "one"
   cout << endl;

   // Test increment
   cout << "Test increment: " << endl;
   ++i;
   cout << (*i)->data << endl; // Should print "two"
   i++;
   cout << (*i)->data << endl; // Should print "three"
   cout << (*i++)->data << endl; // Should print "three"
   cout << (*i)->data << endl; // Should print "four"
   cout << endl;

   // Test decrement
   cout << "Test decrement: " << endl;
   --i;
   cout << (*i)->data << endl; // Should print "three"
   i--;
   cout << (*i)->data << endl; // Should print "two"
   cout << (*i--)->data << endl; // Should print "two"
   cout << (*i)->data << endl; // Should print "one"
   cout << endl;

   // 10-6
   // Test split
   cout << "Exercise 10-6: " << endl;
   cout << "Test split: " << endl;
   Linkedlist list4 = split("Split this string!");
   list4.printList();
   
   return 0;
   }