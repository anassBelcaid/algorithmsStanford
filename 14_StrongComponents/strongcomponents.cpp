#include "strongComponents.h"
#include <fstream>
using std::ifstream;

#include <sstream>
using std::stringstream;

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

StrongComponents::StrongComponents(string filename){

  ifstream in(filename.c_str());

  if(in.bad())
  {
    cerr<<"Can't open the file "<<filename<<endl;
    exit(1);
  }

  string line;
  while(getline(in,line))
  {

    int s, t;
    stringstream stream(line);
    stream>>s>>t;
    
    //adding the edge
    add_edge(s,t,graph);
  }

}

StrongComponents::~StrongComponents(){
}


