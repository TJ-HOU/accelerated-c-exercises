#include <fstream>
#include <string>

using std::endl;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
	ifstream infile("in.txt");
	ofstream outfile("out.txt");

	string s;

	while (getline(infile, s))
		outfile << s << endl;
	return 0;
}