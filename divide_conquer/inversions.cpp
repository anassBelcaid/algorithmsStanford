#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include "inversions.hpp"

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
  vec A =readFile("../IntegerArray.txt");

  auto inv= count_sort(A);
  cout<<"number of inversions is ="<<inv<<endl;
  return 0;

}
