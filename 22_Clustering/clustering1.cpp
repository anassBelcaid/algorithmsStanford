#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
using std::ostream;
using std::istream;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <algorithm>
using std::for_each;
using std::sort;

#include <utility>
#include <vector>
using std::vector;
using veci = vector<int>;
#include "union_find.hpp"


struct edge{  int s;  //source
   int t;  //target
   int w;  //weight;
};

ostream & operator<<(ostream & out, const edge & E){
  out<<E.s<<"--"<<E.t<<", "<<E.w<<endl;
  return out;
}
istream & operator>>(istream & in, edge & E)
{
  in>>E.s>>E.t>>E.w;

  return in;
}

/** Comparator for edges to take the smallest
 */
auto minCmp = [](edge A, edge B){return A.w > B.w;};

int main(int argc, char *argv[]){

  ifstream in("clustering1.txt");

  size_t S;
  in>>S;

  vector<edge> edges;
  edge E;
  while(in>>E)
  {
    edges.push_back(E);
  }

  //sorting the edges
  sort(edges.begin(),edges.end(),minCmp);
  

  //Creating the Union Find
  UnionFind UF(S);

  //loop for clustering
  while(UF.size()>4)
  {
    //getting the closest pair
      auto E=edges.back();

      //connecting the nodes
      UF.link(E.s, E.t);
      
      //Deleting the last element
      edges.pop_back();
    
  }

  cout<<"the maximum distance is "<<edges.back().w<<endl;
  return 0;
}
