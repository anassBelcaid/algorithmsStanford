#ifndef UNION_FIND_H
#define UNION_FIND_H
#include "boost/pending/disjoint_sets.hpp"
using boost::disjoint_sets;

#include <vector>
using veci = std::vector<int>;


/** A class to implement an int based union find from the complex but complete 
 * Disjoint set class fromt the boost library
 */

class UnionFind
{
private:
 veci id;
 veci parents;
 veci elems;
 disjoint_sets<int*,int*> *UF;

public:
  UnionFind(size_t S)
  {
    id= veci(S);
    parents = veci(S);
    elems = veci(S);
    
    for(int i=0;i<S;i++)id[i]=i;
    //should used smart pointer
    UF= new disjoint_sets<int*,int*>(&id[0], &parents[0]);
    for(int i=0;i<S;i++)
    {
      UF->make_set(i);
      elems[i]=i;
    }
  }

  size_t size()const
  {
    return UF->count_sets(elems.begin(),elems.end());
  }

  /** Wrapper for the link function*/
  void link(int i, int j)
  {
    UF->union_set(i,j);
  }

  int get_set(int i)
  {
    return UF->find_set(i);
  }

  bool is_connected(int i, int j)
  {
    return get_set(i)==get_set(j);
  }

  virtual ~UnionFind()
  {
    id.clear();
    parents.clear();
    delete UF;
  }



};

#endif /* UNION_FIND_H */
