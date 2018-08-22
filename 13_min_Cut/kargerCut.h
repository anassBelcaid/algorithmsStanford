#ifndef KARGERCUT_H_BEYZP5HI
#define KARGERCUT_H_BEYZP5HI

#include <vector>
using std::vector;
#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <utility>

#include <unordered_set>
using std::unordered_set;

/* Conventions  */
using vec=std::vector<int>;   //vector of ints
using edge = std::pair<int,int>; //an adge is a pair of ints

class kargerCut
{
public:
  kargerCut (const string  &fileName);
  virtual ~kargerCut ();

  //getters
  size_t V()const;        //number of vertices
  size_t E()const;        //number of edges

  //printstate
  void printState()const;
  
  //contract
  void contract(int label1, int label2);  //contract the edge 

  void random_contract();  //contract a random  edge

  //should be private
  void removeSelfLoops(int idx);

  //main routine
  size_t min_cut();
private:
  /* data */

  vector<edge> edges;
  vector<vec> adj;   //ajdacency list
  vector<unordered_set<int> > labels;

  size_t num_points;       //num Components


};
#endif /* end of include guard: KARGERCUT_H_BEYZP5HI */


