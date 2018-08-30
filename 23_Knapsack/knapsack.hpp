#ifndef KNAPSACK_H
#define KNAPSACK_H
#include <string>
using std::string;
using std::to_string;

#include <vector>
using std::vector;
using veci=vector<int>;
using matrix = vector<veci>;

#include <fstream>
using std::ifstream;

#include <algorithm>
using std::min;
using std::max;


#include <unordered_map>
using std::unordered_map;
using std::make_pair;
using cache= unordered_map<string,long>;   //cache for memoizing

class Knapsack
{
private:
  size_t capacity;
  size_t num_items;
  veci   values;
  veci   weights;
  matrix C;           //memoized capacities
  cache Cc;

  string rep(int i, int j)const
  {
    //representation of the hash map

    string S=to_string(i)+","+to_string(j);

    return S;
  }
public:
  Knapsack(string filename){
    ifstream in(filename.c_str());
    in>>capacity>>num_items;

    cout<<"capasity ="<<capacity<<" num_items="<<num_items<<endl;
  
    values=veci(num_items);
    weights= veci(num_items);
    Cc = cache();

    for(int i=0;i<num_items;i++)
    {
      in>>values[i]>>weights[i];
    }


    //ininialisation of the cost matrix
    /* C = matrix(capacity+1, veci(num_items,0)); */
    //simple sanity check to see if the element exist

    in.close();

  }


  long recursive_computation(int capacity, int element)
  {
      //function to recursivly compute the cost
      //lookup 
      //element is the number of elments;
      auto it = Cc.find(rep(capacity,element));
      if(it!=Cc.end())
        return it->second;

      //base case
      if(element==0)
        return 0;

      //element never been seen before;
      long cost=0;
      int wi = weights[element-1];
      auto v1 = recursive_computation(capacity,element-1);
      if((capacity-wi)>=0)
      {
        auto v2 = recursive_computation(capacity-wi,element-1)+values[element-1];
        cost = max(v1,v2);

      }
      else
      {
        cost = v1;
      }
      
      //caching the cost
      Cc.insert(make_pair(rep(capacity,element),cost));
      return cost;


  }
  long recursive_computation()
  {
    /* auto cost= recursive_computation(capacity,num_items); */
    auto cost = recursive_computation(capacity,num_items);
    return cost;
  }
  void compute_cost_matrix()
  {
    //simple function to recurse to compute the cost matrix

      //loop on each element
      for(int i =0;i<num_items;i++)
      {
          int wi= weights[i];
          for(int cap=1;cap<=capacity;cap++)
          {
            if(cap>=wi)
              C[cap][i]=max(C[cap][i-1], C[cap-wi][i-1]+values[i]);
          else
              C[cap][i]=C[cap][i-1];
          }
      }

}

long optimalValue()
{
  //compute the cose matrix
  compute_cost_matrix();

  return C[capacity][num_items-1];

}
  virtual ~Knapsack(){
    values.clear();
    weights.clear();
  }

};

#endif /* KNAPSACK_H */
