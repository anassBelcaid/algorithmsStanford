#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using std::vector;

#include <string>
using std::string;


using std::make_pair;
//typedefs
using wEdge = std::pair<int,int>;            //Weighted edge
using adjacency = std::vector<vector<wEdge>>;




//enums for graph orientation and color


class Graph
{
private:
  bool is_oriented; 
  adjacency adj;

public:
  Graph(size_t size,bool oriented=true);
  Graph(string filename,bool oriented=true);
  virtual ~Graph();

  /** Api */
  void add_edge(int i, int j,int w);

  //printing
  void printState()const;

  //num vertices
  size_t num_vertices()const;

  //reference on a adjacency
  vector<wEdge> neighbors(int i)const;
  //Getting the transpose
};

#endif /* GRAPH_H */
