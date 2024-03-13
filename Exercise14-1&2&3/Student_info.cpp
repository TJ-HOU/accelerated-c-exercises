#include "Student_info.h"
using std::istream;

istream& Student_info::read(istream& is) 
   {
   char ch;
   is >> ch; // get record type
   // allocate new object of the appropriate type
   // use Handle<T>(T*) to build a Handle<Core> from the pointer to that object
   // call Handle<T>::operator= to assign the Handle<Core> to the left-hand side 
   if (ch == 'U') 
      {
      cp = new Core(is);
      } 
   else 
      {
      cp = new Grad(is);
      }
   return is;
   }

void Student_info::regrade(double final, double thesis)
   {
   // get our own copy before changing the object
   cp.make_unique();
   if (cp)
      {
      cp->regrade(final, thesis);
      }
   else 
      {
      throw std::runtime_error("regrade of unknown student");
      }
   }
