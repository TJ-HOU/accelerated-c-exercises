/*
Exercise 5-9, 5-10, 5-11
See detailed explanation for each exercise in the code.
*/

#include <iostream>
#include "uppers.h"
#include "palindromes.h"
#include "scenders.h"
#include "report.h"

using std::string;
using std::list;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

int main()
   {
   string s;
   list<string> words, results;

   // read and split each line of input 
   while (cin>>s)
      {
      words.push_back(s);
      }

   /*
   Exercise 5-9
   Write the lowercase words in the input followed by the uppercase words.
   Example:
   - Input:
   bib good Morning DEIfied rOtaToR c++ over mnac
   - Output:
   bib
   good
   c++
   over
   mnac
   Morning
   DEIfied
   rOtaToR
   */
   results = words;

   // extract words that contain one or more uppercase letters from the line
   list<string> uppers = extract_uppers(results);

   // append the removed words to the modified line
   results.insert(results.end(),uppers.begin(),uppers.end());

   // write the reordered words
   cout << "Exercise 5-9: " << endl;
   if (results.size()==0)
      {
      cout << "No word is entered." << endl;
      }
   else
      {
      write(results);
      }

   cout << endl;

   /*
   Exercise 5-10
   Find all the palindromes.
   Palindromes are words that are spelled the same right to left as left to right
   Example:
   - Input: Same as Exercise 5-9
   - Output:
   bib
   DEIfied
   rOtaToR
   the longest palindrome is DEIfied
   */
   results = words;
   list<string> palindromes = extract_palindromes(words);

   //write all the palindromes
   cout << "Exercise 5-10: " << endl;
   if (palindromes.size()==0)
      {
      cout << "No palindromes is found." << endl;
      }
   else
      {
      write(palindromes);
      //write the longest palindrome
      cout << "the longest palindrome is " << longest(palindromes) << endl;
      }

   cout << endl;

   /*
   Exercise 5-11 
   Find all the words that contain ascenders or descenders
   Ascenders: b,d,f,h,k,l,t; Descenders: g,j,p,q,y
   Example:
   - Input: Same as Exercise 5-9
   - Output:
   c++
   over
   mnac
   the longest word that has neither ascenders nor descenders: over
   */
   results = words;
   list<string> scenders = extract_scenders(results);

   //write the words that has neither ascenders nor descenders
   cout << "Exercise 5-11: " << endl;
   if (scenders.size()==0)
      {
      cout << "None ascenders or descenders is found." << endl;
      }
   else
      {
      write(results);
      //write the longest word
      cout << "the longest word that has neither ascenders nor descenders: " << longest(results) << endl;
      }

   return 0;   
   }


