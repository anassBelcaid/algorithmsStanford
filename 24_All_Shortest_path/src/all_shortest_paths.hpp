#ifndef ALL_SHORTEST_PATHS_H
#define ALL_SHORTEST_PATHS_H
#include "graph.h"

#include <memory>
using std::unique_ptr;
using std::make_unique;

#include<vector>
using std::vector;
using veci = vector<int>;
using matrix = vector<veci>;


#include <numeric>
const int inf = std::numeric_limits<int>::max();


#include <algorithm>
using std::min;
class AllShortestPaths
{
private:
  unique_ptr<Graph> G;
  matrix D_prev; //disanctes previous
  matrix D;      //actual distances; 

public:
  AllShortestPaths(string filename)
  {
    G = make_unique<Graph>(filename,true);
    
    auto n = G->num_vertices();

    //filling the matrix
    D_prev =matrix(n,veci(n,inf));
    D      = matrix(n,veci(n,inf));


    //filling the matrix
    for(int i=0;i<n;i++)
    {
      D_prev[i][i]=0;
      for ( auto edge : G->neighbors(i)) {
        D_prev[i][edge.first]= edge.second; 
      }
      D=D_prev;
    }
  };

  void computeShortestPaths()
  {
    /** Loop to compute the distances
     */
    auto n  = G->num_vertices();
    for(auto k=0;k<n;k++)
    {
        for(int i=0;i< n;i++)
          for (int j = 0; j < n; ++j) {
            if( D_prev[i][k]<inf && D_prev[k][j]<inf)
            
             D[i][j]= min(D_prev[i][j], D_prev[i][k]+D_prev[k][j]);
          }

        //update D_prev
        /* cout<<"-------------------------"<<endl; */
        /* for (auto L: D) { */
        /*  for(auto v: L) */
        /*    if(v<inf) */
        /*      cout<<v<<" "; */
        /*    else */
        /*      cout<<"inf "; */
        /*  cout<<endl; */
          
        /* } */
        /* cout<<"-------------------------"<<endl; */
        D_prev= D;
    }
  }
  int shortestpath()const
  {
    int m=inf;

    for(auto L:D)
    {
      for(auto v: L)
        m = min(v,m);
    }
    return m;
  }

  bool has_cycle()const
  {
    auto n=G->num_vertices();
    for(int i=0;i<n;i++)
      if(D[i][i]<0)
        return true;
    return false;
  }
  virtual ~AllShortestPaths()
  {
    D_prev.clear();
    D.clear();
  };
};

#endif /* ALL_SHORTEST_PATHS_H */
