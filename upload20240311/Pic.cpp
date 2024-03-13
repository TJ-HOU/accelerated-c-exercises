#include "Pic.h"

void Pic_base::pad(std::ostream& os, wd_sz beg, wd_sz end)
   {
   while (beg != end) 
      {
      os << " ";
      ++beg;
      }
   }

// String_Pic
Pic_base::wd_sz String_Pic::width() const
   {
   Pic_base::wd_sz n = 0;
   for (auto i = 0; i != data.size(); ++i)
      {
      n = std::max(n, data[i].size());
      }
   return n;
   }
Pic_base::ht_sz String_Pic::height() const
   {
   return data.size();
   }
void String_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const
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

// Frame_Pic   
Pic_base::wd_sz Frame_Pic::width() const
   {
   return p->width() + 4; 
   }
Pic_base::ht_sz Frame_Pic::height() const
   {
   return p->height() + 4; 
   }
void Frame_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const
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
            // change corner and top/bottom characters
            os << crn << Str(width()-2, tb) << crn;
            } 
         else if (row == 1 || row == height() - 2) 
            {
            // second from top or bottom row
            // change side characters
            os << sd;
            pad(os, 1, width() - 1);
            os << sd;
            } 
         else 
            {
            // interior row
            // change side characters
            os << sd << " ";
            p->display(os, row - 2, true);
            os << " " << sd;
            }
         }
   } 
// 15-4 Add a reframe operation so that users can specify what character 
// to use for the corners, the top/bottom borders, and the side borders
void Frame_Pic::reframe (char a, char b, char c)
   {
   crn = a;
   tb = b;
   sd = c;
   } 

// VCat_Pic
Pic_base::wd_sz VCat_Pic::width() const
   { 
   return std::max(top->width(), bottom->width()); 
   }
Pic_base::ht_sz VCat_Pic::height() const
   { 
   return top->height() + bottom->height(); 
   }
void VCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const
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

// HCat_Pic
Pic_base::wd_sz HCat_Pic::width() const 
   {
   return left->width() + right->width(); 
   }
Pic_base::ht_sz HCat_Pic::height() const 
   {
   return std::max(left->height(), right->height()); 
   }
// 15-5 Reimplement HCat_Pic so that when pictures of a different size are concatenated, 
// the shorter one is centered in the space consumed by the longer one.
void HCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const
   {
   if(left->height() > right->height())
      {
      left->display(os, row, true);
      ht_sz up = (left->height()-right->height())/2;
      if (row >= up && row < up+right->height())
         {
         right->display(os, row - up, do_pad);
         }   
      }
   else
      {
      ht_sz up = (right->height()-left->height())/2;
      if (row >= up && row < up+left->height())
         {
         left->display(os, row - up, true);
         } 
      else
         {
         pad(os, 0, left->width());
         }
      right->display(os, row, do_pad);
      }
   }

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


   
