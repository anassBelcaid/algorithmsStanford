#include <iostream>
using std::cout;
using std::endl;
#include "kargerCut.h"

#include <ctime>
using std::time;
using std::srand;

const int max_iter=1E2;

int main(int argc, char *argv[])
{


  srand(time(0));
  kargerCut A("kargerMinCut.txt");

  auto min_cut= A.min_cut();

  for(int i=1;i<max_iter;i++)
  {
    kargerCut A("kargerMinCut.txt");
    auto cut_size=A.min_cut();

    min_cut=(min_cut<cut_size)?min_cut:cut_size;
  }
  
  cout<<"min cut size ="<<min_cut<<endl;
  return 0;
}
