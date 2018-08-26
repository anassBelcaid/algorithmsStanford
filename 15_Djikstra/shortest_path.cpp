#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include <algorithm>
using std::for_each;

#include <utility>

#include "single_shortest_paths.hpp"

int main(int argc, char *argv[])
{

  Graph G("dijkstra.txt");
  /* Graph G("tinyEWD.txt"); */

  single_shortest_paths paths(G);
  paths.compute_paths(0);
  auto dis= paths.getdistances();

  //query distances
  vector<int> query{6,36,58,81,98,114,132,164,187,196};
  for(auto v : query)
    cout<<v+1<<"--->"<<dis[v]<<endl;
  return 0;
}
