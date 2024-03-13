/*
Exercise 7-6
Given a grammar, generate a sentence according to the <sentence> rule.
The exercise asks not using any recursive calls.
Hint: using 2 vectors, one for return and the other as a stack.

Input:
<noun>	      cat
<noun>	      dog
<noun> 	      table
<noun-phrase>	<noun>
<noun-phrase>	<adjective> <noun-phrase>
<adjective>	   large
<adjective>	   brown
<adjective>	   absurd
<verb>		   jumps
<verb>		   sits
<location>	   on the stairs
<location>	   under the sky
<location>	   wherever it wants
<sentence>	   the <noun-phrase> <verb> <location>

Output (The output can be different because it is randomly generated.):
the absurd cat sits under the sky
the dog jumps wherever it wants
the brown absurd dog jumps on the stairs
the large table sits on the stairs
the cat jumps on the stairs
*/
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<cstdlib>
#include<ctime>

using std::cout;
using std::string;
using std::vector;
using std::map;
using std::endl;
using std::cin;
using std::istream;
using std::rand;
using std::domain_error;
using std::logic_error;

/*
The entire input is an example of Grammar.
The left column is Rule. The right column is Rule_collection.
*/
typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

// predicate to determine whether a char is a space
bool space(char c)
   {
   return isspace(c);
   }

// predicate to determine whether a char is not a space
bool not_space(char c)
   {
   return !isspace(c);
   }

// split a string into a vector of string
vector<string> split(const string& str)
   {
   typedef string::const_iterator iter;
   vector<string> ret;
   iter i = str.begin();

   while (i != str.end()) 
      {
      // ignore leading blanks
      i = find_if(i, str.end(), not_space);
      // find end of next word
      iter j = find_if(i, str.end(), space);
      // copy the characters in [i, j)
      if (i != str.end())
         {
         ret.push_back(string(i, j));
         }
      i = j;
      }
   return ret;
   }

// read a grammar into a map from a given input stream 
Grammar read_grammar(istream& in)
   {
   Grammar ret;
   string line;
   // read the input
   while (getline(in, line)) 
      {
      // split the input into words 
      vector<string> entry = split(line);
      if (!entry.empty())
         {
         // use the category to store the associated rule
         ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
         }
      }
   return ret;
   }

// predicate to determine whether a string is bracketed
bool bracketed(const string& s)
   {
   return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
   }

// return a random integer in the range [0, n)
int nrand(int n)
   {
   if (n <= 0 || n > RAND_MAX)
      {
      throw domain_error("Argument to nrand is out of range");
      }

   const int bucket_size = RAND_MAX / n;
   int r;
   do 
      {
      r = rand() / bucket_size;
      }
   while (r >= n);
   return r;
   }

// Randomly select a rule that corresponds to the input string from Grammar.
// For example, if word is "<noun>", 
// it will randomly return 1 of the top 3 rule collections in the given Grammar.
vector<string> rule_extract(const Grammar& g, const string& word)
   {
   // locate the rule that corresponds to word
   auto it = g.find(word);
   if (it == g.end())
      {
      throw logic_error("empty rule");
      }

   // fetch the set of possible rules
   const Rule_collection& c = it->second;

   // from which we select one at random
   const Rule& r = c[nrand(c.size())];
   vector<string> theRule;
   for (auto i = r.begin(); i != r.end(); ++i)
      {
      theRule.push_back(*i);
      }

   return theRule;
   }

// generate sentence without using recursive calls.
vector<string> gen_sentence(const Grammar& g)
   {
   vector<string> SenRule = rule_extract(g, "<sentence>");

   vector<string> ret,RuleStacks;
   for (vector<string>::const_reverse_iterator it = SenRule.rbegin(); it != SenRule.rend(); ++it)
      {
      RuleStacks.push_back(*it);
      }
   while (!RuleStacks.empty())
      {
      string word = RuleStacks.back();
      RuleStacks.pop_back();
      if (bracketed(word))
         {
         vector<string> nextRule = rule_extract(g, word);
         for (vector<string>::const_reverse_iterator it = nextRule.rbegin(); it != nextRule.rend(); ++it)
            {
            RuleStacks.push_back(*it);
            }
         }
      else
         {
         ret.push_back(word);       
         }
      }
   return ret;
   }

int main() 
   {
   Grammar g = read_grammar(cin);

   // generate the sentence
   std::srand(static_cast<unsigned int>(std::time(nullptr)));

   for (int i=0; i!=5; ++i)
      {
      vector<string> sentence = gen_sentence(g);

      // write the first word, if any
      auto it = sentence.begin();
      if (!sentence.empty()) 
         {
         cout << *it;
         ++it;
         }

      // write the rest of the words, each preceded by a space 
      while (it != sentence.end()) 
         {
         cout << " " << *it;
         ++it;
         }
      cout << endl;
      }
   
   return 0;
   }

