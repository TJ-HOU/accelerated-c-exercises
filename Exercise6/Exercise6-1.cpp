#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using std::string;
using std::vector;
using std::max;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;

    for (vector<string>::const_iterator it = v.begin();it != v.end(); ++it)
        maxlen = max(maxlen, (*it).size());

    return maxlen;

}

vector<string> frame(const vector<string>& v) {
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    // write the top border
    ret.push_back(border);

    // write each interior row, bordered by an asterisk and a space 
    for (vector<string>::const_iterator it = v.begin();it != v.end(); ++it){
        ret.push_back( "* " + *it +
        string(maxlen - (*it).size(), ' ') + " *");
    }
    
    // write the bottom border 
    ret.push_back(border);
    return ret;

}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;
    typedef vector<string>::const_iterator iter;
    
    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;
    
    // indices to look at elements from left and right respectively 
    iter i = left.begin(), j = right.begin();
    
    // continue until we've seen all rows from both pictures
    while (i != left.end() || j != right.end()) {
        // construct new string to hold characters from both pictures
        string s;
        
        // copy a row from the left-hand side, if there is one 
        if (i != left.end()){
            s=(*i++);
        }

            
        // pad to full width
        s += string(width1 - s.size(), ' ');
        
        // copy a row from the right-hand side, if there is one
        if (j != right.end()){
            s += *(j++);
        }
            
        // add s to the picture we're creating 
        ret.push_back(s);
    }
    return ret;
}


int main(){
    string s;
    vector<string> v;
     
    while (getline(cin, s)) 
        v.push_back(s);

    vector<string> result;
    result = frame(v);
    cout << "frame: " << endl << endl;
    for (vector<string>::size_type i = 0; i != result.size(); ++i)
        cout << result[i] << endl;
    
    cout << endl;

    cout << "horizontal frame: " << endl << endl;
    vector<string> hresult;
    hresult = hcat(v,result);
    for (vector<string>::size_type i = 0; i != hresult.size(); ++i)
        cout << hresult[i] << endl;
    
    cout << endl;

    return 0;   
}

