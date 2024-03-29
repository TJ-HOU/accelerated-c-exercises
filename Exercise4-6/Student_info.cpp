#include "Student_info.h"
#include "grade.h"

using std::istream; 
using std::vector;
using std::domain_error;

// read homework grades from an input stream into a vector<double>
vector<double>& read_hw(istream& in, vector<double>& hw) {
   if (in) {
      // get rid of previous contents 
      hw.clear() ;

      // read homework grades 
      double x;
      while (in >> x){
         hw.push_back(x);
      }
    
      // clear the stream so that input will work for the next student
      in.clear();
   }

   return hw;

}

istream& read(istream& is, Student_info& s){
   
   double midterm;
   double final;
   std::vector<double> hw;
   
   // read and store the student's name and midterm and final exam grades
   is >> s.name >> midterm >> final;

   // read and store all the student's homework grades
   hw = read_hw(is, hw); 

   try{

   s.grade = grade(midterm,final,hw);

   }catch(domain_error e){
 
      s.grade = -1;

   }

   return is;

}

bool compare(const Student_info& x, const Student_info& y){

   return x.name < y.name;

}


