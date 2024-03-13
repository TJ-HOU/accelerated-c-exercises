/*
15-4 Add a reframe operation so that users can specify what character 
     to use for the corners, the top/bottom borders, and the side borders
15-5 Reimplement HCat_Pic so that when pictures of a different size are concatenated, 
     the shorter one is centered in the space consumed by the longer one.
15-6 Use Vec and Str to implmenet Pictures
*/
#ifndef GUARD_Pic_h
#define GUARD_Pic_h

#include <iostream>
#include <algorithm>

// 15-6 Use Vec and Str to implmenet Pictures
#include "Vec.h"
#include "Str.h"
#include "Ptr.h"

// forward declaration, described in 15.3/288
class Picture;

// private classes for use in the implementation only 
class Pic_base 
   {
   public:
      virtual ~Pic_base() 
      { 
      };
      // 15-4 Add a reframe operation so that users can specify what character 
      // to use for the corners, the top/bottom borders, and the side borders
      virtual void reframe(char, char, char) = 0;
   private:
      friend std::ostream& operator<<(std::ostream&, const Picture&);
      friend class Frame_Pic;
      friend class HCat_Pic;
      friend class VCat_Pic;
      friend class String_Pic; 

      typedef Vec<Str>::size_type ht_sz;
      typedef Str::size_type wd_sz;

      virtual wd_sz width() const = 0;
      virtual ht_sz height() const = 0;
      virtual void display(std::ostream&, ht_sz, bool) const = 0;

   protected:
   static void pad(std::ostream&, wd_sz, wd_sz);
   };

class String_Pic: public Pic_base 
   {
   friend class Picture;
   Vec<Str> data;
   String_Pic(const Vec<Str>& v): data(v) 
      {
      }
   wd_sz width() const;
   ht_sz height() const;
   void display(std::ostream&, ht_sz, bool) const;
   void reframe(char, char, char)
      {
      }  
   };

class Frame_Pic: public Pic_base 
   {
   friend Picture frame(const Picture&);
   Ptr<Pic_base> p;
   char crn; // specify characters for corners
   char tb; // specify characters for top and bottom borders
   char sd; // specify characters for side borders
   Frame_Pic(const Ptr<Pic_base>& pic): p(pic),crn('#'),tb('*'),sd('^')
      {
      }
   wd_sz width() const;
   ht_sz height() const;
   void display(std::ostream&, ht_sz, bool) const;
   void reframe (char, char, char); 
   };
class VCat_Pic: public Pic_base 
   {
   friend Picture vcat(const Picture&, const Picture&);
   Ptr<Pic_base> top, bottom;
   VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b): top(t), bottom(b) 
      {
      }
   wd_sz width() const;
   ht_sz height() const;
   void display(std::ostream&, ht_sz, bool) const;
   void reframe (char, char, char)
      {
      } 
   };
class HCat_Pic: public Pic_base 
   {
   friend Picture hcat(const Picture&, const Picture&);  
   Ptr<Pic_base> left, right;
   HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r): left(l), right(r) 
      {
      }
   wd_sz width() const;
   ht_sz height() const;
   void display(std::ostream&, ht_sz, bool) const;
   void reframe (char, char, char)
      {
      }
   };

// public interface class and operations
class Picture 
   {
   friend std::ostream& operator<<(std::ostream&, const Picture&);
   friend Picture frame(const Picture&);
   friend Picture hcat(const Picture&, const Picture&);
   friend Picture vcat(const Picture&, const Picture&);  
   public:
      Picture(const Vec<Str>& v= Vec<Str>()): p(new String_Pic(v)) 
         {
         }
      void reframe(char a, char b, char c) 
         {
         p->reframe(a, b, c); 
         }
   private:
      Ptr<Pic_base> p;
      Picture(Pic_base* ptr): p(ptr) 
         {
         }
   };

Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);

#endif