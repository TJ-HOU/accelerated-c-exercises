#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>


using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::domain_error;

template<class T>
T median(vector<T> v)
{
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();
    if (size == 0)
    throw domain_error("median of an empty vector");
    sort(v.begin(), v.end());

    vec_sz mid = size/2;
    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

// implmentation requires input iterator
template <class In, class X> 
In myfind(In begin, In end, const X& x)
   {
   while (begin != end && *begin != x)
      {
      ++begin;
      }
   return begin;
   }

template <class In, class X> In find2(In begin, In end, const X& x)
{
    if (begin == end || *begin == x)
    return begin;
    begin++;
    return find(begin, end, x);
}

// implmentation requires input and output iterator
template<class In, class Out>
Out mycopy(In begin, In end, Out dest)
   {
   while (begin != end)
      {
      *dest++ = *begin++;
      }  
   return dest;
   }

template<class For, class X>
void myreplace(For beg, For end, const X& x, const X& y)
{
    while (beg != end)
    {
    if (*beg == x)
    *beg = y; 
    ++beg;
    }
}

template<class X> void myswap(X& a, X& b)
   {
      X tmp = a;
      a = b;
      b = tmp;
   }
   
// implmentation requires bidirectional iterator
template<class Bi> void myreverse(Bi begin, Bi end)
   {
   while (begin != end) 
      {
      --end;
      if (begin != end)
         {
         myswap(*begin++, *end);
         }
      }
   }

template<class Ran, class X>
bool mybinary_search(Ran begin, Ran end, const X& x)
{
    while (begin < end) {
    // find the midpoint of the range
    Ran mid = begin + (end - begin) / 2;
    // see which part of the range contains x; keep looking only in that part 
    if (x < *mid)
    end = mid;
    else if (*mid < x)
    begin = mid + 1;
    // if we got here, then *mid == x so we're done 
    else return true;
    }
    return false;
}

bool space(char c)
   {
   return isspace(c);
   }

bool not_space(char c)
   {
   return !isspace(c);
   }

template <class Out> // changed
void split(const string& str, Out os) { // changed
    typedef string::const_iterator iter;
    iter i = str.begin();
    while (i != str.end()) {
    // ignore leading blanks
    i = find_if(i, str.end(), not_space);
    // find end of next word
    iter j = find_if(i, str.end(), space);
    // copy the characters in [i, j)
    if (i != str.end())
    *os++ = string(i, j); // changed
    i = j;
    }
}

int main()
{
   vector<int> v = {1, 2, 3, 4, 5};
   vector<int> c(v.size());
   cout << median(v) << endl;
   cout << *(find2(v.begin(),v.end(),3))<< endl;
   mycopy(v.begin(),v.end(),c.begin());
   myreplace(c.begin(),c.end(),3,5);
   for (int num : c){
      cout << num << endl;
   }
   cout << mybinary_search(c.begin(), c.end(), 3) << endl;
   cout << mybinary_search(c.begin(), c.end(), 5) << endl;

   split("example",std::ostream_iterator<string>(cout, "\n"));
   return 0;

}