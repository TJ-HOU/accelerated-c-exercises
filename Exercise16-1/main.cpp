#include <iostream>
#include <fstream>

int main() 
   {
   std::ifstream sourceFile(__FILE__); // Open this source file
   std::string line;

   while (std::getline(sourceFile, line)) 
      { // Read the file line by line
      std::cout << line << std::endl; // Print each line to standard output
      }

   return 0;
   }
