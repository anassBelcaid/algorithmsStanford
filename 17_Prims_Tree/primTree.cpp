#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::for_each;
using std::min;
using std::find;
#include <unordered_set>
using std::unordered_set;

#include <limits>
const auto infty = std::numeric_limits<int>::max();
#include <utility>
#include "graph.h"

auto myCmp = [](wEdge E1, wEdge E2){return E1.second>E2.second;};


//Function to relax or update the distance to a  node

void update_distance(vector<wEdge> & front, const wEdge edge)
{

  //find the positoin of the edge
  int i;
  for(int i=0;front.size();i++)
    if(front[i].first==edge.first)
    {
        front[i].second=min(front[i].second, edge.second);
        return;
    }
}

int main(int argc, char *argv[])
{
  Graph G("edges.txt",false);
  auto n = G.num_vertices();
  cout<<"n="<<n<<endl;
  long cost=0;       //cost of the minimal spanning tree

  //frontier;
  vector<wEdge> front(n);
  unordered_set<int> S;

  //insert all the nodes as unreachable
  for(int i =0;i<n; i++)
    front[i]=make_pair(i,infty);

  front[0].second=0;
  make_heap(front.begin(),front.end(),myCmp);

  //First node in the frontier;
  S.insert(0);

  while(S.size()<n)
  {
      //getting the minimal element
      auto E=front.front(); pop_heap(front.begin(),front.end(),myCmp);front.pop_back();
      /* cout<<"taking edge ="<<E.first<<"--"<<E.second<<endl; */
      auto node = E.first;
      auto dist= E.second;
      cost+=dist;           //dist is absolutely in the mst
      /* cout<<"inserting "<<node<<" in the set"<<endl; */
      S.insert(node);

      for(auto edge: G.neighbors(node))
      {
        //check if the neighbors is not in the frontier
         if(S.find(edge.first)==S.end())
         {
           update_distance(front,edge);
         }
      }
      make_heap(front.begin(),front.end(),myCmp);

      /* cout<<"frontier="<<endl; */
      /* for(auto E:front)cout<<E.first<<"-"<<E.second<<endl; */
      
  }

  cout<<"Cost of the MST is "<<cost<<endl;
  return 0;
  
}
