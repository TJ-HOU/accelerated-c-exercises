/* 
11-8. Write a simplified version of the standard list class and its associated iterator
10-4. Write a class that implements a list that holds strings.
10-5. Write a bidirectional iterator for your string list class.
10-6. Test the class by rewriting the split function to put its output into a string list.
*/

#ifndef GUARD_llist_h
#define GUARD_llist_h

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

// Node class to represent a node of the linked list. 
class Node 
   { 
   public: 
      string data; 
      Node* next; 
      Node* prev;

      Node() 
         { 
         data = ""; 
         next = NULL; 
         prev = NULL;
         }  
      Node(string data) 
         { 
         this->data = data; 
         this->next = NULL; 
         this->prev = NULL;
         } 
   };

class NodeItr 
   { 
   public: 
      NodeItr()
         {
         d = new Node();
         }
      NodeItr(Node* node)
         {
         d = node;
         }
      Node* operator*()
         {
         return d;
         }
      //prefix decrement
      NodeItr& operator++()
         {
         d = d->next;
         return *this;
         }
      //postfix decrement
      NodeItr operator++(int) 
         {
         NodeItr ret(*this); 
         operator++(); 
         return ret;
         }
      NodeItr& operator--()
         {
         d = d->prev;
         return *this;
         }
      NodeItr operator--(int) 
         {
         NodeItr tmp(*this); 
         operator--(); 
         return tmp;
         }
      bool operator == (NodeItr it) const
         {
         return (d == *it);
         }
      bool operator != (NodeItr it) const
         {
         return (d != *it);
         }
   private:
      Node* d;
   };  

class Linkedlist 
   {  
   public:  
      Linkedlist() 
         {
         head = NULL; 
         } 
      Linkedlist(string s) 
         {
         head = new Node(s); 
         } 
      Linkedlist(size_t n, string s) 
         {
         head = new Node(s);
         for (size_t i = 1; i < n; i++)
            {
            appendNode(s);
            }
         } 

      NodeItr begin()
         {
         return NodeItr(head);
         }
      const NodeItr begin() const
         {
         return NodeItr(head);
         }
      NodeItr end()
         {
         return NodeItr(NULL);
         }
      const NodeItr end() const
         {
         return NodeItr(NULL);
         }

      size_t size();
      // push back a node to the linked list
      void appendNode(string); 
      // delete the node at given position 
      void deleteNode(NodeItr);
      // insert the node at given position 
      void insertNode(NodeItr, string);
      // reverse the linked list
      void reverse();
      // append a linked list
      void append(Linkedlist);
      // print the linked list. 
      void printList();   
   private:
      Node* head; 
   }; 

#endif