#include "kargerCut.h"
#include <iostream>
using std::cerr;
using std::getline;
using std::cout;
using std::endl;
using std::make_pair;

#include <sstream>
using std::stringstream;

#include <algorithm>
using std::find;

kargerCut::kargerCut(const string  &filename)
{

  //constructor with a file name
  //
  ifstream in(filename.c_str());

  if(in.bad())
  {
    cerr<<"Couldn't open the file"<<endl;
    exit(1);
  }

  string line;
  while(getline(in,line))
  {
    stringstream SS(line);
    //getting the id
    int id;
    SS>>id;

    //adding teh:b 
    vec nei;        //neighbor vector
    int j;
    while(SS>>j)
    {
      nei.push_back(j);

      //Cant count edges twice
      if(id<j)
        edges.push_back(make_pair(id,j));
    }
    unordered_set<int> S{id};
    labels.push_back(S);
    adj.push_back(nei);
  }

  //number of components
  num_points=adj.size();


}


void kargerCut::random_contract()
{
   //random selection of an element
   auto idx = rand()%edges.size();
   auto E= edges[idx];

   //contract the edge
   contract(E.first,E.second);
}

kargerCut::~kargerCut()
{
  edges.clear();
}

size_t kargerCut::V()const
{
  return adj.size();
}
size_t kargerCut::E()const
{
  return edges.size();
}

void kargerCut::printState()const
{
  cout<<"-------------------------------"<<endl;
  for(int i=0;i<V();i++)
  {
    //printting the labels
    for(int v:labels[i])
      cout<<v<<", ";
    cout<<": ";
    
    for(int v: adj[i])
      cout<<v<<", ";
    cout<<endl;

  }

  /* cout<<"list of edges:"<<endl; */
  /* for(auto E:edges) */
  /*   cout<<E.first<<"--"<<E.second<<endl; */
  /* cout<<"-------------------------------"<<endl; */
  
}

void kargerCut::removeSelfLoops(int idx)
{
  //assert idw >0 and idx< initial nodes:

  for(auto v : labels[idx])
  {
    //if we find the element we remove it (too long)
    
    //find the element 
    auto it = find(adj[idx].begin(),adj[idx].end(),v);
    
    while(it!= adj[idx].end())
    {
        adj[idx].erase(it);
        it= find(adj[idx].begin(),adj[idx].end(),v);
    }

  }

  //updating the edges
  edges.clear();


  for(int i=0;i<adj.size();i++)
  {

    if(labels[i].size()!=0)
    {
      auto label= *(labels[i].begin());
      
      //adding the edges
      for(auto v  : adj[i])
        edges.push_back(make_pair(label,v));
    }
  }

}

void kargerCut::contract(int label1 , int label2)
{

  //seek the adjacency containing label1
  int i,j;
  for(i =0;i<adj.size();i++)
  {
    if(labels[i].find(label1) != labels[i].end())
      break;
  }

  //seek the adjacency containing label2
  for(j =0;j<adj.size();j++)
  {
    if(labels[j].find(label2) != labels[j].end())
      break;
  }


  //adding the ajdacency of j to i
  for(auto v : adj[j])
    adj[i].push_back(v);
  
  //removing the labels from labels j and put them in i
  for(auto v: labels[j])
    labels[i].insert(v);

  labels[j].clear();


  //removing self loops
  removeSelfLoops(i);
  //clearing j
  adj[j].clear();


  //Decreasing the number of components
  num_points--;

}

size_t kargerCut::min_cut()
{

  while(num_points>2)
  {
    random_contract();
  }

  //lenght of the cut is size of the first non empty adj
  for(auto node:adj)
  {
    if(node.size()!=0)
      return node.size();
  }

  return 0;
}

