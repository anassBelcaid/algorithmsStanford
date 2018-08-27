#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
#include <string>
using std::string;
#include <algorithm>
using std::for_each;
#include <utility>
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <boost/unordered_map.hpp>
using boost::unordered_map;
using std::make_pair;


//alias
using vec=vector<long>;
using hashTable = unordered_map<long,long>;
vec readFromFile(string filename){
  vec A;
  ifstream in(filename.c_str());
  if(!in)
  {
    cerr<<"Cannot find file "<<filename<<endl;
    exit(1);
  }
  long val;
  while(in>>val)
  {
    A.push_back(val);
  }
  in.close();
  return A;
}


int main(int argc, char *argv[]){
  
  const long rangMin=-10000;
  const long rangMax=10000;
  int count=0;

  vec A=readFromFile("algo1-programming_prob-2sum.txt"); 
  /* vec A=readFromFile("example.txt"); */


  //building the lookup table
  hashTable table;
  table.max_load_factor(0.2);
  for(auto v: A)
    table.insert(make_pair(v,v));
  cout<<"max load factor "<<table.load_factor()<<endl;

  for(auto t=rangMin;t<=rangMax;t++)
  {
    auto diff =(t-rangMin);
    if((diff%100)==0)
      cout<<float(diff)/(rangMax-rangMin)<<endl;
    for(auto p:table)
      if(table.find(t-p.first)!=table.end())
        {
          count++;
          break;
        }
        
  }
  
  cout<<"number of targets is "<<count<<endl;

  return 0;
}
