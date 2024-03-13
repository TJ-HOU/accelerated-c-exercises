#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <map>

using std::vector;
using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::isspace;
using std::istream;

bool not_url_char(char c)
{
    // characters, in addition to alphanumerics, that can appear in a URL
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    // see whether c can appear in a URL and return the negative
    return !(isalnum(c) ||
    find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}

string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";
    typedef string::const_iterator iter;
    // i marks where the separator was found
    iter i = b;
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
    // make sure the separator isn't at the beginning or end of the line
    if (i != b && i + sep.size() != e) {
    // beg marks the beginning of the protocol-name
    iter beg = i;
    while (beg != b && isalpha(beg[-1]))
    --beg;
    // is there at least one appropriate character before and after the separator?
    if (beg != i && !not_url_char(i[sep.size()]))
    return beg;
    }
    // the separator we found wasn't part of a URL advance i past this separator
    i += sep.size();
    }
    return e;
}

vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();
    // look through the entire input
    while (b != e) {
        // look for one or more letters followed by ://
        b = url_beg(b, e);
        // if we found it
        if (b != e) {
        // get the rest of the URL
        iter after = url_end(b, e);
        // remember the URL
        ret.push_back(string(b, after));
        // advance b and check for more URLs on this line
        b = after;
        }
    }
    return ret;
}

// find all the lines that refer to each word in the input 
map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = find_urls)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;
    // read the next line 
    while (getline(in, line)) {
        ++line_number;
    // break the input line into words
    vector<string> words = find_words(line);
    // remember that each word occurs on the current line
    for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
    {
        ret[*it].push_back(line_number);
    }
        
    }
    return ret;
}

int main()
{
    // call xref using split by default
    map<string, vector<int> > ret = xref(cin);
    // write the results
    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) 
    {
        cout << it->first << " occurs on ";
        if (it->second.size()==1)
        {
            cout << "line: ";
        }
        else
        {
            cout << "line(s): ";
        }
        
        // followed by one or more line numbers
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it; //write the first line number
        ++line_it;
        // write the rest of the line numbers, if any
        while (line_it != it->second.end()) {
        cout << ", " << *line_it;
        ++line_it;
        }
        // write a new line to separate each word from the next
        cout << endl;
    }
    
    return 0;
    
}
