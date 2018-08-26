#include "graph.h"
using std::make_heap;
using std::push_heap;
using std::pop_heap;
#include <algorithm>
using std::min;

#include <unordered_set>
using std::unordered_set;
using iset = unordered_set<int>;      //set of ints to represent the frontier;

/* Edge comparator to take always edge with the smallest hop
 */
auto wEdge_comp = [](wEdge a, wEdge b){ return a.second> b.second;};

//max distance in homework
const int maxDis = 1000000;

class single_shortest_paths

{
public:
  single_shortest_paths (Graph & graph):G(graph)
  {
  };
  virtual ~single_shortest_paths ()
  {
    distances.clear();
  }

void compute_paths(int source)
  {
    //compute the single paths from a source S
    initialize_single_source(source);
   

    //main loop on the priority
    while(priority.size()>0)
    {
      auto edg = extrac_min();

      //distance of the node;
      distances[edg.first]= edg.second;
      for(auto J : G.neighbors(edg.first))
        relax(edg.first,J.first,J.second);
      heapify();

    /* cout<<"----------------------------------"<<endl; */
    /* for(auto edg: priority) */
      /* cout<<edg.first<<"-->"<<edg.second<<endl; */
    }

  
  }
void relax(int s, int t, int w){
  //this is the most difficult task
  //search the position of t in  the priority queue
  for(int i=0;i<priority.size();i++)
  {
    if(priority[i].first==t)
    {
      priority[i].second= min(distances[s]+w,priority[i].second);
      return;
    }
  }
}
void initialize_single_source(int s){

  int n = G.num_vertices();
  distances=vector<int>(n);
  for(auto &v : distances)
    v=maxDis;
  distances[s]=0;

  //create the heap file with the actual disances;
  priority = vector<wEdge>(n);
   for( int i=0;i<n;i++)
      priority[i]= make_pair(i,distances[i]);
}
void heapify(){
  // wrap up to heapify the priority queue
 make_heap(priority.begin(),priority.end(),wEdge_comp);
}
wEdge extrac_min(){
//wraup up to extract the min from the priorirty

  wEdge M= priority.front();
  priority.erase(priority.begin());
  make_heap(priority.begin(),priority.end(),wEdge_comp);
  /* pop_heap(priority.begin(),priority.end(),wEdge_comp); */
  return M;
}
vector<int> getdistances()const
{
  return distances;
}
private:
  /* data */
  Graph & G;
  vector<int> distances;  //distances;
  vector<wEdge> priority;
  /* vector<int> parent;     // to get the paths */
};
