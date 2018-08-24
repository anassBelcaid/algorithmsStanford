#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using std::vector;

#include <string>
using std::string;

//typedefs
using adjacency = std::vector<vector<int>>;



//enums for graph orientation and color


class Graph
{
private:
  bool is_oriented; 
  adjacency adj;

public:
  Graph(size_t size,bool oriented=true);
  Graph(string filename);
  virtual ~Graph();

  /** Api */
  void add_edge(int i, int j);

  //printing
  void printState()const;

  //num vertices
  size_t num_vertices()const;

  //reference on a adjacency
  vector<int> neighbors(int i)const;
  //Getting the transpose
  Graph  transpose()const;
};

#endif /* GRAPH_H */
