#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include <algorithm>
using std::for_each;

#include <utility>

#include "strongComponents.h"
#include "graph.h"
#include "./strongly_connected_components.hpp"

int main(int argc, char *argv[])
{

  Graph G("SCC.txt");
  /* Graph G("./example1.txt"); */

  strongly_connected_components C(G);

  C.construct_size_vector();
  return 0;
}
