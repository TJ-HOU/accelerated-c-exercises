/*
Exercise 8-2
Implement the following library algorithm and 
specify what kinds of iterators they require

equal(b, e, d) 
search(b, e, b2, e2)
find_if(b, e, p)
remove_copy(b, e, d, t)
remove_copy_if(b, e, d, p) 
remove(b, e, t)
transform(b, e, d, f) 
partition(b, e, p)
accumulate(b, e, t)

Example outputs can be in comments.
*/

#include <vector>
#include <iostream>
#include <stdexcept>

using std::vector;
using std::cout;
using std::endl;
using std::distance;
using std::domain_error;

// forward declaration
template <class In, class X> 
bool myequal(In begin1, In end1, X begin2);
template <class For1, class For2> 
For1 mysearch(For1 begin1, For1 end1, For2 begin2, For2 end2);
template <class In,class Predicate> 
In myfind_if(In begin, In end, Predicate p);
template<class In, class Out, class X>
Out myremove_copy(In begin, In end, Out dest, const X& x);
template<class In, class Out, class Predicate>
Out myremove_copy_if(In begin, In end, Out dest, Predicate p);
template<class For, class X>
For myremove(For begin, For end, const X& x);
template<class In, class Out, typename Function>
Out mytransform(In begin, In end, Out dest, Function f);
template<class X> void myswap(X& a, X& b);
template <class Bi,typename Predicate> 
Bi mypartition(Bi begin, Bi end, Predicate p);
template<class In, class X>
X myaccumulate(In begin, In end, const X& x);
template<class T,class Ran>
T mymedian(Ran begin, Ran end);

// implmentation requires input iterator
template <class In, class X> 
bool myequal(In begin1, In end1, X begin2)
   {
   while(begin1!=end1 && *begin1 == *begin2)
      {
      ++begin1;
      ++begin2;
      } 
   return (begin1==end1);
   }

// implmentation requires forward iterator
template <class For1, class For2> 
For1 mysearch(For1 begin1, For1 end1, For2 begin2, For2 end2)
   {
   while(*begin1 != *begin2 && begin1 != end1)
      {
      ++begin1;
      }
   if (begin1 != end1)
      {
      For1 start = begin1;
      while(*begin1 == *begin2)
         {
         ++begin1;
         ++begin2;
         }
      if (begin2==end2)
         {
         return start;
         }
      } 
   return end1;
   }

// implmentation requires input iterator
template <class In,class Predicate> 
In myfind_if(In begin, In end, Predicate p)
   {
   while (begin != end && !p(*begin))
      {
      ++begin;
      }
   return begin;
   }

// implmentation requires input and output iterator
template<class In, class Out, class X>
Out myremove_copy(In begin, In end, Out dest, const X& x)
   {
   while (begin != end)
      {
      if (*begin != x)
         {
         *dest++ = *begin++; 
         }
      else
         {
         begin++;
         }        
      }
   return dest;
   }

// implmentation requires input and output iterator
template<class In, class Out, class Predicate>
Out myremove_copy_if(In begin, In end, Out dest, Predicate p)
   {
   while (begin != end)
      {
      if (!p(*begin))
         {
         *dest++ = *begin++; 
         }
      else
         {
         begin++;
         }        
      }
   return dest;
   }

// implmentation requires forward iterator
template<class For, class X>
For myremove(For begin, For end, const X& x)
   {
   auto newend = begin;
   while (begin != end)
      {
      if (*begin != x)
         {
         *newend++ = *begin++; 
         } 
      else
         {
         begin++;
         }      
      }
   return newend;
   } 

// implmentation requires input and output iterator
template<class In, class Out, typename Function>
Out mytransform(In begin, In end, Out dest, Function f)
   {
   while (begin != end)
      {
      *dest++ = f(*begin++);   
      }
   return dest;
   }

// swap the value of a and b
template<class X> void myswap(X& a, X& b)
   {
      X tmp = a;
      a = b;
      b = tmp;
   }

// implmentation requires bidirectional iterator
template <class Bi,typename Predicate> 
Bi mypartition(Bi begin, Bi end, Predicate p)
   {
   while (begin != end)
      {
      if (!p(*begin))
         {
         myswap(*begin,*(--end));
         }
      else
         {
         ++begin;
         }
      }
   return end;
   } 

// implmentation requires input iterator
template<class In, class X>
X myaccumulate(In begin, In end, const X& x)
   {
   X ret = 0;
   while (begin != end)
      {
      ret = ret + *begin;
      ++begin;   
      }
   return ret;
   }

// implmentation requires random-access iterator
template<class T,class Ran>
T mymedian(Ran begin, Ran end)
   {
   ptrdiff_t size = end - begin;
   if (size == 0)
      {
      throw domain_error("median of an empty vector");
      }
   sort(begin,end);
   ptrdiff_t mid = size/2;
   return size % 2 == 0 ? (*(begin+mid) + *(begin+mid-1)) / 2.0 : *(begin+mid); 
   }

int main()
{
// Predicate function to check if a number is even
auto isEven = [](int x) { return x % 2 == 0; };

vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> v2 = {2, 3, 4, 5};
vector<int> v3 = {2, 3, 4, 5};

// Check if v1 == v2
// Output: v1 and v2 are not equal.
if (myequal(v1.begin(), v1.end(), v2.begin())) 
   {
   cout << "v1 and v2 are equal." << endl;
   } 
else 
   {
   cout << "v1 and v2 are not equal." << endl;
   }

// Check if v2 == v3
// Output: v2 and v3 are equal.
if (myequal(v2.begin(), v2.end(), v3.begin())) 
   {
   cout << "v2 and v3 are equal." << endl;
   } 
else 
   {
   cout << "v2 and v3 are not equal." << endl;
   }
cout << endl;

// Find the 1st occurrence of v2 within v1
// Output: Found the sequence at position: 1
auto it = mysearch(v1.begin(), v1.end(), v2.begin(), v2.end());
if (it != v1.end()) 
   {
   cout << "Found the sequence at position: " << distance(v1.begin(), it) << endl;
   } 
else 
   {
   cout << "Sequence not found." << endl;
   }
cout << endl;

// Find the 1st element in v1 that is even
// Output: First even number found: 2
it = myfind_if(v1.begin(), v1.end(), isEven);
if (it != v1.end()) 
   {
   cout << "First even number found: " << *it << endl;
   } 
else 
   {
   cout << "No even number found." << endl;
   }
cout << endl;

// Copy vector v1 to vector destination,omitting elements == 5
// Output: 1 2 3 4 6 7 8 9 
vector<int> destination(v1.size()); 
int valueToRemove = 5;
auto endIterator = myremove_copy(v1.begin(), v1.end(), destination.begin(), valueToRemove);
int numElementsAfterRemoval = distance(destination.begin(), endIterator);
cout << "Remove 5 from input:" << endl;
for (int i = 0; i < numElementsAfterRemoval; ++i) 
   {
   cout << destination[i] << " ";
   }
cout << endl << endl;

// Copy all non-even elements in vector v1 to vector destination
// Output: 1 3 5 7 9 
vector<int> odds(v1.size());
endIterator = myremove_copy_if(v1.begin(), v1.end(), odds.begin(), isEven);
numElementsAfterRemoval = distance(odds.begin(), endIterator);
cout << "Remove even elements:" << endl;
for (int i = 0; i < numElementsAfterRemoval; ++i) 
   {
   cout << odds[i] << " ";
   }
cout << endl << endl;

// Remove all elements == 20 from vector v4
// Output: range contains: 10 30 30 10 10
int v4[] = {10,20,30,30,20,10,10,20};
int* pbegin = v4;                          
int* pend = v4 + sizeof(v4)/sizeof(int);                      
pend = myremove (pbegin, pend, 20); 
cout << "Remove 20 from input:";
for (int* p=pbegin; p!=pend; ++p)
   {
   cout << ' ' << *p;
   }
cout << endl << endl;

// Square all elements in vector v1
// Output: 1 4 9 16 25 36 49 64 81 
vector<int> squared(v1.size());
mytransform(v1.begin(), v1.end(), squared.begin(), [](int x) { return x * x; });
cout << "Squared of input elements: " << endl;
for (int num : squared) 
   {
   cout << num << " ";
   }
cout << endl << endl;

// Sum all elements in vector v1
// Output: Sum of elements: 45
int sum = myaccumulate(v1.begin(), v1.end(), 0);
cout << "Sum of elements: " << sum << endl << endl;

// Partition vector v1 so that even numbers precede odd numbers
// Output: Partitioned vector: 8 2 6 4 | 5 7 3 9 1
auto partitionPoint = mypartition(v1.begin(), v1.end(), isEven);
cout << "Partitioned vector:";
for (auto it = v1.begin(); it != partitionPoint; ++it) 
   {
   cout << " " << *it;
   }
cout << " |";
for (auto it = partitionPoint; it != v1.end(); ++it) 
   {
   cout << " " << *it;
   }
cout << endl << endl;

// Compute median of vector v1
// Output: Median: 5
try 
   {
   cout << "Median: " << mymedian<double>(v1.begin(),v1.end()) << endl;
   } 
catch (domain_error e) 
   {
   cout << e.what() << endl;
   }

return 0;
}

