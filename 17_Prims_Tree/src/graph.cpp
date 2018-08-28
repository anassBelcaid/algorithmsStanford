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
  adj = vector<vector<wEdge> > (size);
}

Graph::Graph(string filename,bool orientation)
{

  ifstream in(filename.c_str());

  int n;
  in>>n;
  *this= Graph(n,orientation);
  int m;
  in>>m;       //bizzarly now they introduce the number of edges ????
  string line;
  //completing the line
  getline(in,line);
  while(getline(in,line))
  {
    int s, t,w;
    stringstream stream(line);
    stream>>s>>t>>w;
    //adding the edge
    add_edge(s-1,t-1,w);
    /* add_edge(s,t,w); */
  }


}
void Graph::add_edge(int i, int j,int w){
  assert(i>=0 && j>=0); 
  assert(i<adj.size() && j <adj.size());
  //getting the max of i and j
  adj[i].push_back(make_pair(j,w));

  //if not oriented add also j-->i
  if(!is_oriented)
    adj[j].push_back(make_pair(i,w));
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
        cout<<"("<<nei.first<<", "<<nei.second<<") ,";
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

vector<wEdge> Graph::neighbors(int i)const
{
  return adj[i];
}

size_t Graph::num_vertices()const
{
  return adj.size();
   }
