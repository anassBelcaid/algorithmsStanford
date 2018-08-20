#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;
#include "quickSort.hpp"

vec readFile(string fileName)
{

    ifstream in(fileName.c_str());
    if(!in)
    {
      cerr<<"Cannot open the input file"<<endl;
      exit(1);
    }

    int val;
    vec A;

    while(in>>val)
    {
      A.push_back(val);
    }



    return A;
}

int main(int argc, char *argv[])
{
  vec A=readFile("QuickSort.txt");

  auto comp = Quick_Sort(A);
  cout<<is_sorted(A.begin(),A.end())<<endl;

  cout<<"number of comparaison is "<<comp<<endl;
  return 0;

}
