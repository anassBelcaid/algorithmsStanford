#ifndef STRONGLY_CONNECTED_COMPONENTS_CPP_ANIBMOBU
#define STRONGLY_CONNECTED_COMPONENTS_CPP_ANIBMOBU

#include "depth_first_search.hpp"

#include <algorithm>
using std::sort;
using std::unique;
using std::count;
#include <numeric>
using std::iota;

#include <iostream>
using std::cout;
using std::endl;

#include <unordered_set>
using std::unordered_set;

class strongly_connected_components
{
public:
  strongly_connected_components (Graph & G)
  {
      auto n = G.num_vertices();
      order=vector<int>(n);
      components = vector<int>(n);

      //Execute the first pass
      depth_first_search first_pass(G);
      first_pass.DFS();
      
      //getting the order
      auto F = first_pass.finish;  //finishing times
      iota(order.begin(), order.end(), 0);
      auto comparator=[&F](int a, int b){ return F[a]>F[b];};
      sort(order.begin(),order.end(),comparator);

     
      //DFS on transpose
      auto T=G.transpose();

      depth_first_search second(T);
      second.DFS(order);
      
      components = second.comp;

  }
  virtual ~strongly_connected_components ()
  {
      components.clear();
      order.clear();
  }

  void construct_size_vector()
  {
      
    unordered_set<int> S;
    vector<int> sizes;

    //soring the sizes
    sort(components.begin(),components.end());

    //sizes;
    int count=1;
    int i=0;
    auto  n= components.size();
    while(i<n-1)
    {
     while(components[i]==components[i+1])
     {
        count++;
        i++;
     }

     sizes.push_back(count);
     count=1;
     i++;
    }

    sort(sizes.begin(),sizes.end(),[](int a, int b){return a>b;});
    for(i=0;i<5;i++)
    cout<<sizes[i]<<" ";
    cout<<endl;
  }
private:
  vector<int> components;
  vector<int> order;
};

#endif /* end of include guard: STRONGLY_CONNECTED_COMPONENTS_CPP_ANIBMOBU */
