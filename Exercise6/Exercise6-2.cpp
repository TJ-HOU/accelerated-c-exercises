// g++ -std=c++11
#include <vector>
#include <string>
#include <iostream>
#include <cctype>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::isspace;

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

int main(){

   // true if the argument is whitespace, false otherwise
    
    vector<string> input = {
        "Have you tried http://google.co.uk and http://bbc.co.uk ?",
        "Have you tried http:// or google.co.uk or http://google.co.uk ?",
        "Have you tried http or :// or http://bbc.co.uk ?"
        };

    vector<string> ret;
    for (vector<string>::const_iterator i = input.begin(); i != input.end(); ++i){
        ret = find_urls(*i);
        for (vector<string>::const_iterator it = ret.begin(); it != ret.end(); ++it)
        cout << *it << endl;
        cout << endl;
    } 
    
    return 0;
}
