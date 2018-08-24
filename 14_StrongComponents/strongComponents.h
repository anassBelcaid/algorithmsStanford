#ifndef STRONGCOMPONENTS_H
#define STRONGCOMPONENTS_H
/** Implement the strong components algorithm
 */

#include <string>
using std::string;

#include "boost/graph/adjacency_list.hpp"
using boost::adjacency_list;


class StrongComponents
{
public:
  adjacency_list<> graph;

public:
  StrongComponents(string fileName);
  virtual ~StrongComponents();
};

#endif /* STRONGCOMPONENTS_H */

