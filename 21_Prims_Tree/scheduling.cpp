#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
using std::ostream;
#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <algorithm>
using std::for_each;
using std::sort;

#include <utility>
using std::make_pair;
#include <vector>
using std::vector;
//alias for a job
using job = std::pair<int,int>;


//simple rooting so print a jor
ostream & operator<<(ostream & out, const job & J)
{
  out<<"("<<J.first<<", "<<J.second<<")\n";
  return out;
}


//scheduler based on difference weight(first) - length(second)
auto firstCmp =[](job J1, job J2){
  auto diff1 = (J1.first-J1.second);
  auto diff2 = (J2.first - J2.second);
  if(diff1<diff2)
    return true;
  else if( diff1>diff2)
    return false;
  else
    return (J1.first<J2.first);
};

auto secondCmp= [](job J1, job J2)
{
  auto r1= float(J1.first)/J1.second;

  auto r2 = float(J2.first)/J2.second;
  return r1<r2;
};
int main(int argc, char *argv[])
{

  ifstream in("./jobs.txt");

  size_t N;
  in>>N;
  cout<<"size of jobs is ="<<N<<endl;

  vector<job> pending(N);      //pending

  for(auto i=0;i<N;i++)
  {
    int w, l;
    in>>w>>l;

    pending[i]=make_pair(w,l);
  }

  //make heap
  sort(pending.begin(),pending.end(),secondCmp);
  long obj=0;      //ojective function sum of weighted finishing times
  auto finish=0;   //finish time
  while(pending.size())
  {
    auto J = pending.back();pending.pop_back(); 
    finish+=J.second;
    obj+= J.first* finish;
  }

  cout<<"Weighted finishing time="<<obj<<endl;

  return 0;
}
