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

#include <vector>
using std::vector;
#include <utility>

#include <unordered_map>
using std::unordered_map;

#include "union_find.hpp"


int main(int argc, char *argv[])
{
  ifstream in("clustering_big.txt");  
  /* ifstream in("Test.txt"); */  

  size_t S,num_b;

  in>>S>>num_b;
  unordered_map <string,int> nodes;
  int val;
  UnionFind UF(S);
  for(int i=0;i<S;i++)
  {
      char bits[num_b+1];
      bits[num_b]='\0';
      for(int j=0;j<num_b;j++)
      {
        
        in>>val;
        bits[j]=(val)?'1':'0';
      }

      //if already in maps just connect theme
      auto V=string(bits);
      //see if v already exist on the maps
      auto it= nodes.find(V);

      if(it==nodes.end())
        nodes.emplace(V,i);
      else
      {

        UF.link(i,it->second);
      }

  }




  for(auto P:nodes)
  {
    auto rep=P.first;
    auto i=P.second;

    //liner scan
    for(int pos=0;pos<num_b;pos++)
    {
      string Second(rep);
      Second[pos]=(rep[pos]=='1')?'0':'1';
      
      auto it=nodes.find(Second);

      if(it!=nodes.end())
      {
        UF.link(i,it->second);
      }

      //Quadratic search
      for(int pos2=pos+1;pos2<num_b;pos2++)
      {
        string Second(rep);
        Second[pos]=(rep[pos]=='1')?'0':'1';
        Second[pos2]=(rep[pos2]=='1')?'0':'1';
      
        auto it=nodes.find(Second);

        if(it!=nodes.end())
        {
          UF.link(i,it->second);
        }

      }
    }

    //second search
  }

  cout<<UF.size()<<endl;
  in.close();
  return 0;
}
