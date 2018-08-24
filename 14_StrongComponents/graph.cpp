#include "graph.h"
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
#include <cassert>


#include <fstream>
using std::ifstream;
#include <sstream>
using std::stringstream;

Graph::Graph(size_t size, bool orientation){
  this->is_oriented = orientation;
  adj = vector<vector<int> > (size);
}

Graph::Graph(string filename)
{

  ifstream in(filename.c_str());

  int n;
  in>>n;
  *this= Graph(n);
  string line;
  //completing the line
  getline(in,line);
  while(getline(in,line))
  {
    int s, t;
    stringstream stream(line);
    stream>>s>>t;
    //adding the edge
    add_edge(s-1,t-1);
  }


}
void Graph::add_edge(int i, int j){
  assert(i>=0 && j>=0); 
  assert(i<adj.size() && j <adj.size());
  //getting the max of i and j
  adj[i].push_back(j);

  //if not oriented add also j-->i
  if(!is_oriented)
    adj[j].push_back(i);
}
void Graph::printState()const{
  cout<<"------------------------------"<<endl;
  for(int i=0;i<adj.size();i++)
  {
    auto L=adj[i];
    if(L.size()>0)
    {
      cout<<i<<": ";
      for(auto nei: L)
        cout<<nei<<" ,";
      cout<<endl;
    }
  }
  cout<<"---------------------------------"<<endl;
}
Graph::~Graph(){
  for(int i=0;i<adj.size();i++)
    adj[i].clear();

  adj.clear();
}
Graph  Graph::transpose()const{
  auto n = adj.size();

  Graph T(n,is_oriented);

  for(int i=0;i<n;i++)
  {
    auto L = adj[i];
    
    if(is_oriented)
    for(auto v : L)
      T.add_edge(v,i);
    else
      T.adj[i]=L;
  }

  return T;
}

vector<int> Graph::neighbors(int i)const
{
  return adj[i];
}

size_t Graph::num_vertices()const
{
  return adj.size();
   }
