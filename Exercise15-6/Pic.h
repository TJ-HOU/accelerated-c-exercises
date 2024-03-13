#ifndef GUARD_Pic
#define GUARD_Pic

#include <iostream>
#include <algorithm>

#include "Ptr.h"
#include "Vec.h"
#include "Str.h"

// forward declaration, described in 15.3/288
class Picture;

// private classes for use in the implementation only 
class Pic_base 
   {
   public:
      virtual ~Pic_base() 
      { 
      };
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
   static void pad(std::ostream& os, wd_sz beg, wd_sz end)
      {
      while (beg != end) 
         {
         os << " ";
         ++beg;
         }
      }
   };

class String_Pic: public Pic_base 
   {
   friend class Picture;
   Vec<Str> data;
   String_Pic(const Vec<Str>& v): data(v) 
      {
      }
   wd_sz width() const
      {
      Pic_base::wd_sz n = 0;
      for (auto i = 0; i != data.size(); ++i)
         {
         n = std::max(n, data[i].size());
         }
      return n;
      }
   ht_sz height() const
      {
      return data.size();
      }
   void display(std::ostream& os, ht_sz row, bool do_pad) const
      {
      wd_sz start = 0;
      // write the row if we're still in range 
      if (row < height()) 
         {
         os << data[row];
         start = data[row].size(); 
         }
      // pad the output if necessary 
      if (do_pad)
         {
         pad(os, start, width());
         }
      }
   void reframe(char, char, char)
      {
      }  
   };

class Frame_Pic: public Pic_base 
   {
   friend Picture frame(const Picture&);
   Ptr<Pic_base> p;
   char crn;
   char tb;
   char sd;
   Frame_Pic(const Ptr<Pic_base>& pic): p(pic),crn('#'),tb('*'),sd('^')
      {
      }
   wd_sz width() const
      {
      return p->width() + 4; 
      }
   ht_sz height() const
      {
      return p->height() + 4; 
      }
   void display(std::ostream& os, ht_sz row, bool do_pad) const
      {
      if (row >= height()) 
         {
         // out of range 
         if (do_pad)
            {
            pad(os, 0, width());
            }
         } 
         else 
            {
            if (row == 0 || row == height() - 1) 
               {
               // top or bottom row
               os << crn << Str(width()-2, tb) << crn;
               } 
            else if (row == 1 || row == height() - 2) 
               {
               // second from top or bottom row
               os << sd;
               pad(os, 1, width() - 1);
               os << sd;
               } 
            else 
               {
               // interior row
               os << sd << " ";
               p->display(os, row - 2, true);
               os << " " << sd;
               }
            }
      } 
   // Exercise 15-4
   void reframe (char a, char b, char c)
      {
      // p->reframe(a,b,c);
      crn = a;
      tb = b;
      sd = c;
      }  
   };
class VCat_Pic: public Pic_base 
   {
   friend Picture vcat(const Picture&, const Picture&);
   Ptr<Pic_base> top, bottom;
   VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b): top(t), bottom(b) 
      {
      }
   wd_sz width() const
      { 
      return std::max(top->width(), bottom->width()); 
      }
   ht_sz height() const
      { 
      return top->height() + bottom->height(); 
      }
   void display(std::ostream& os, ht_sz row, bool do_pad) const
      {
      wd_sz w = 0;
      if (row < top->height()) 
         {
         // we are in the top subpicture
         top->display(os, row, do_pad);
         w = top->width();
         } 
      else if (row < height()) 
         {
         // we are in the bottom subpicture
         bottom->display(os, row - top->height(), do_pad);
         w = bottom->width();
         }
      if (do_pad)
         {
         pad(os, w, width());
         }
      }
   void reframe (char, char, char)
      {
      //top->reframe(a,b,c);
      //bottom->reframe(a,b,c);
      } 
   };
class HCat_Pic: public Pic_base 
   {
   friend Picture hcat(const Picture&, const Picture&);  
   Ptr<Pic_base> left, right;
   HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r): left(l), right(r) 
      {
      }
   wd_sz width() const 
      {
      return left->width() + right->width(); 
      }
   ht_sz height() const 
      {
      return std::max(left->height(), right->height()); 
      }
   // Exercise 15-4
   void display(std::ostream& os, ht_sz row, bool do_pad) const
      {
      ht_sz left_row = row;
      ht_sz right_row = row;
      if (left->height() > right->height())
         {
         ht_sz up = (height()-right->height())/2;
         right_row = (row < up) ? right->height() : row - up;
         }
      else
         {
         ht_sz up = (height()-left->height())/2;
         left_row = (row < up) ? left->height() : row - up;
         }
      left->display(os, left_row, do_pad || right_row < right->height());
      right->display(os, right_row, do_pad); 
      }
   void reframe (char, char, char)
      {
      //left->reframe(a,b,c);
      //right->reframe(a,b,c);
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
      Picture(const Vec<Str>& v): p(new String_Pic(v)) 
         {
         }
   private:
      Ptr<Pic_base> p;
      Picture(Pic_base* ptr): p(ptr) 
         {
         }
   };

Picture frame(const Picture& pic) 
   {
   return new Frame_Pic(pic.p);
   }
Picture hcat(const Picture& l, const Picture& r)
   {
   return new HCat_Pic(l.p, r.p);
   }
Picture vcat(const Picture& t, const Picture& b)
   {
   return new VCat_Pic(t.p, b.p);
   }
std::ostream& operator<<(std::ostream& os, const Picture& picture)
   {
   const Pic_base::ht_sz ht = picture.p->height();
   for (auto i = 0; i != ht; ++i) 
      {
      picture.p->display(os, i, false);
      os << std::endl;
      }
   return os;
   }

#endif