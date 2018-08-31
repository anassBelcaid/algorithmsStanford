#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include <algorithm>
using std::for_each;

#include "src/all_shortest_paths.hpp"

int main(int argc, char *argv[])
{

  AllShortestPaths paths("./g3.txt"); 

  paths.computeShortestPaths();

  if(paths.has_cycle())
    cout<<"The path has a cycle"<<endl;
  else
    cout<<"Shortest path in the graph is "<<paths.shortestpath()<<endl;
  return 0;
}
