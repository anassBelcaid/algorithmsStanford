#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include <algorithm>
using std::for_each;

#include <utility>

#include "knapsack.hpp"

int main(int argc, char *argv[])
{

  Knapsack K("./knapsack_big.txt");
  /* Knapsack K("./debuging1.txt"); */

  cout<<"Finished computing the cost matrix"<<endl;
  /* cout<<K.optimalValue()<<endl; */
  cout<<K.recursive_computation()<<endl;


  return 0;
}
