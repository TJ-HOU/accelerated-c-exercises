#include<string>
#include<vector>
#include<iostream>
#include<map>

using std::cout;
using std::string;
using std::vector;
using std::map;
using std::endl;
using std::cin;
using std::pair;

bool cmp(pair<string, int> const &a, pair<string, int> const &b) {
  return a.second < b.second;
}

int main()
{
    string s;
    map<string, int> counters; // store each word and an associated counter

    // read the input, keeping track of each word and how often we see it 
    while (cin >> s)
    ++counters[s];  

    vector<pair<string, int> > v(counters.begin(), counters.end());
    sort(v.begin(),v.end(),cmp);

    // write the words and associated counts
    for (vector<pair<string, int> >::const_iterator it = v.begin();it != v.end(); ++it) {
    cout << it->first << "\t" << it->second << endl;
    }

    return 0;

}