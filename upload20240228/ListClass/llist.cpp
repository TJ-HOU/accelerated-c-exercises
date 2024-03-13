#include "llist.h"

// Find length of the linked-list.
size_t Linkedlist::size()
   {
   Node *temp1 = head; 
   size_t ListLen = 0; 
   if (head != NULL) 
      {   
      while (temp1 != NULL) 
         { 
         temp1 = temp1->next; 
         ListLen++; 
         } 
      }
   return ListLen;   
   }

// push back a new node. 
void Linkedlist::appendNode(string data) 
   {  
   Node* newNode = new Node(data); 
   if (head == NULL) 
      { 
      head = newNode; 
      return; 
      } 
   Node* temp = head; 
   while (temp->next != NULL) 
      { 
      temp = temp->next; 
      } 
   temp->next = newNode; 
   newNode->prev = temp;
   } 

// delete the node at given position 
void Linkedlist::deleteNode(NodeItr it) 
   { 
   if (*it == NULL) 
      { 
      cout << "Invalid Node." << endl; 
      return; 
      }  
   Node *temp1 = *it;
   it++;
   (*it)->prev = temp1;
   temp1->next = *it;
   }

// insert the node at given position 
void Linkedlist::insertNode(NodeItr it, string data) 
   {
   Node* newNode = new Node(data); 
   if (*it == head) 
      { 
      head = head->next;  
      head->prev = *it;
      return; 
      }
   if (*it == NULL)
      {
      appendNode(data);
      }
   Node* temp1 = *it;
   it--;
   Node* temp2 = *it;
   temp2->next = newNode;
   temp1->prev = newNode;
   newNode->prev = temp2;
   newNode->next = temp1;
   }

void Linkedlist::reverse()
   {
   Node* curr = head;
   Node* prev = NULL;
   Node* next = NULL;
   while (curr != NULL)
      {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      }
   head = prev;
   }

void Linkedlist::append(Linkedlist ll)
   {
   NodeItr it1 = ll.begin();
   while (it1!=ll.end())
      {
      appendNode((*it1)->data);
      it1++;
      }
   }

// print the nodes of the linked list. 
void Linkedlist::printList() 
   { 
   Node* temp = head; 
   if (head == NULL) 
      { 
      cout << "List empty" << endl; 
      return; 
      } 
   while (temp != NULL) 
      { 
      cout << temp->data << endl; 
      temp = temp->next; 
      } 
   cout << endl;
   } 