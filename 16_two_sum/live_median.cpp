#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include <algorithm>
using std::for_each;
#include <fstream>
using std::ifstream;

#include <utility>
using std::make_heap;
using std::push_heap;
using std::pop_heap;
#include <vector>
using std::vector;

auto minCmp =[](int a, int b){return a>b;};

class live_median
{
public:
  live_median ()
  {
    leftHeap = vector<int>();
    rightHeap = vector<int>();
    median=0;
    size=0;
  }
  virtual ~live_median (){};

  int getMedian()const
  {
    return median;
  }

  void insert_value(int v)
  {
    if(size==0)
    {
      median=v;
      size++;
      return ;
    }
    //insert a new value to the stack
    if(size%2)
    {
      //odd size
      if(median<v)
      {
        leftHeap.push_back(median);
        make_heap(leftHeap.begin(),leftHeap.end());
        rightHeap.push_back(v);
        make_heap(rightHeap.begin(),rightHeap.end(),minCmp);
        size++;
      }
      else
      {
        rightHeap.push_back(median);
        make_heap(rightHeap.begin(),rightHeap.end(),minCmp);
        leftHeap.push_back(v);
        make_heap(leftHeap.begin(),leftHeap.end());
        median=leftHeap.front();
        size++;
      }
    }
    else
    {
      //even size
      if(v>median)
      {
        rightHeap.push_back(v);
        make_heap(rightHeap.begin(),rightHeap.end(),minCmp);
        median = rightHeap.front();
        rightHeap.erase(rightHeap.begin());
        size++;
      }
      else
      {
        leftHeap.push_back(v);
        make_heap(leftHeap.begin(),leftHeap.end());
        median=leftHeap.front();
        leftHeap.erase(leftHeap.begin());
        size++;
      }
    }
  }
private:
  vector<int> leftHeap;
  vector<int> rightHeap;
  int median;
  int size;
};
int main(int argc, char *argv[])
{
  long median=0;    //acutual median
  
  //reading the file
  ifstream in("Median.txt");
  /* ifstream in ("simpleMedian.txt"); */
  int val;
  live_median L;
  while(in>>val)
  {
    L.insert_value(val);
    median+=L.getMedian();
  } 
  cout<<median%10000<<endl;
  in.close();

  return 0;
}
