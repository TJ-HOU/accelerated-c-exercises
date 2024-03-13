/*
Exercise 5-1
Design and implement a program to produce a permuted index. 
A permuted index is one in which each phrase is indexed by every word in the phrase.

Example:
- Input:
The quick brown fox
^D
- Output:
                    The quick brown fox
      The quick     brown fox                             
The quick brown     fox                             
            The     quick brown fox                      
*/
#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include "split.h"
#include "cat.h"
#include "permute.h"
#include "read.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::sort;

int main()
   {    
   // read each line of the input 
   string line;
   vector<string> lines;   
   lines=read(cin);
   cout << endl;

   // for each line
   for (vector<string>::size_type i = 0; i != lines.size(); ++i)
      {
      // split the line into words, separated by space
      vector<string> words = split(lines[i]);

      // rotate the line
      /*
      Example:
      - Input: 
      The quick brown fox
      - Output:
      The quick brown fox
      quick brown fox The
      brown fox The quick
      fox The quick brown
      */
      vector<string> r = rotate(words);

      // sort the rotations
      /*
      Example:
      - Output:
      The quick brown fox
      brown fox The quick
      fox The quick brown
      quick brown fox The
      */
      sort(r.begin(),r.end());

      // unrotate the rotations
      /*
      Example:
      - Output:
                        The quick brown fox
      The quick         brown fox                               
      The quick brown   fox
      The               quick brown fox   
      */
      vector<string> ur = unrotate(r,words[0],words.back());

      // write the permuted index
      for (vector<string>::size_type i = 0; i != ur.size(); ++i)
         {
         cout << ur[i] << endl;
         }
      }

   return 0;   
   }