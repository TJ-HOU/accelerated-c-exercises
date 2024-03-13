#ifndef GUARD_String_list_h
#define GUARD_String_list_h

#include <string>
using std::string;
#include <memory>

class String_list 
   {
   public:
   typedef string* iterator; 
   typedef const string* const_iterator; 
   typedef size_t size_type; 

   String_list() 
      { 
      create(); 
      }
   String_list(size_type n, const string& s) 
      { 
      create(n, s); 
      }
   String_list(const String_list& sl) // copy constructor
      { 
      data = alloc.allocate(sl.end() - sl.begin());
      avail = data + sl.size();
      } 
   String_list(const_iterator b, const_iterator e) 
      {
      create(b, e);
      }
   ~String_list() 
      { 
      uncreate(); 
      }
   String_list& operator=(const String_list&);
   size_type size() const 
      { 
      return avail - data; 
      }
   iterator begin() 
      { 
      return data; 
      } 
   const_iterator begin() const 
      { 
      return data; 
      } 
   iterator end() 
      { 
      return avail; 
      } 
   const_iterator end() const 
      { 
      return avail; 
      } 
   void clear() 
      { 
      uncreate(); 
      }
   void push_back(const string&);
   String_list& reverse();
   String_list& append(const String_list&);
     
   private:
   iterator data;
   iterator avail;
   std::allocator<string> alloc;
   void create() ;
   void create(size_type, const string&);
   void create(const_iterator, const_iterator);
   void uncreate();
   };

void String_list::create()
   {
   data = avail = 0;
   }

void String_list::create(size_type n, const string& val)
   {
   data = alloc.allocate(n);
   avail = data + n;
   std::uninitialized_fill(data, avail, val);
   }

void String_list::create(const_iterator i, const_iterator j)
   {
   data = alloc.allocate(j - i);
   avail = std::uninitialized_copy(i, j, data);
   }

void String_list::uncreate()
   {
   if (data) 
      {
      // destroy (in reverse order) the elements that were constructed
      iterator it = avail;
      while (it != data)
         {
         alloc.destroy(--it);
         }
      // return all the space that was allocated
      alloc.deallocate(data, avail - data);
      }
   // reset pointers to indicate that the Vec is empty again
   data = avail = 0;
   }

String_list& String_list::operator=(const String_list& rhs)
   {
    // check for self-assignment
    if (&rhs != this) 
       {
        // free the array in the left-hand side
        uncreate();
        // copy elements from the right-hand to the left-hand side
        create(rhs.begin(),rhs.end());
       }
    return *this;
   }
   
void String_list::push_back(const string& s)
   {
   iterator newdata = alloc.allocate(avail - data+1);
   iterator newavail = newdata + (avail - data) + 1;
   std::uninitialized_copy(data, avail, newdata);
   alloc.construct(newavail-1, s);
   uncreate();
   data = newdata;
   avail = newavail;
   }

String_list& String_list::reverse()
   {
   iterator newdata = alloc.allocate(size()+1);
   iterator newavail = newdata + size();
   size_type count = 0;
   auto rit = newdata;
   auto it = avail - 1;
   while (count < (size()+1))
      {
      *rit=*it;
      it--;
      rit++;
      count++;
      }
   uncreate();
   data = newdata;
   avail = newavail;
   return *this; 
   }

String_list& String_list::append(const String_list& rhs)
   {
   size_type newlength = size()+rhs.size();
   iterator newdata = alloc.allocate(newlength);
   iterator newavail = newdata + newlength;
   std::uninitialized_copy(data, avail, newdata);
   std::uninitialized_copy(rhs.begin(), rhs.end(), newdata + size());
   uncreate();
   data = newdata;
   avail = newavail;
   return *this;
   }

bool operator==(const String_list& lhs, const String_list& rhs) 
      {
      if(lhs.size()!=rhs.size())
         {
         return false;
         }
      else
         {
         auto rit = rhs.begin();
         for (auto it = lhs.begin(); it!= lhs.end(); it++)
            {
               if(*rit == *it)
               {
               rit++;
               } 
            else
               {
               return false;
               }
            }
         }
      return true;
      }

bool operator!=(const String_list& lhs, const String_list& rhs) 
   {
   return !(lhs==rhs);
   }

#endif