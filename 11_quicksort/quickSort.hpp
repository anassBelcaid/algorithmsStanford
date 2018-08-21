/** implement the quick sort with thre given strategies */

#include <iostream>
using std::cout;
using std::endl;


#include <vector>
using vec= std::vector<int>;

#include <algorithm>
using std::for_each;
using std::iter_swap;


template <class T>
void printV(const std::vector<T> &V){
  for_each(V.begin(),V.end(),[](T a) {cout<<a<<" ";});
  cout<<endl;
}

int partition(vec &A, int s, int f,int & pivotPos){
  //Partition the array from s to f
  // pivot Position
  auto n = (f-s);

  /* cout<<"s="<<s<<" f="<<f<<endl; */
  /* printV(A); */

  //option for last element
  // swtich the last element to be the pivot
  /* iter_swap(A.begin()+s,A.begin()+f-1); */
  

  //option of the middle between( S, middl, F)
  auto mid=(n%2==0)?(n/2 - 1): (n/2);
  mid+=s;

  //index of the middle
  int mid_idx;

  //case if the last element in middle
    /* cout<<"comparaing between :"<<endl; */
    /* cout<<A[s]<<" "<<A[mid]<<" "<<A[f-1]<<endl; */
    if(A[s]< A[mid])
      {
        if(A[s]>A[f-1])
        mid_idx=s;
        else
        mid_idx= (A[mid]<A[f-1])?mid:f-1;
      }
    else
      {
      if(A[s]<A[f-1])
        mid_idx=s;
        else
        mid_idx= (A[mid]>A[f-1])?mid:f-1;
      }

    //swap if necessary
  /* cout<<"median is ="<<A[mid_idx]<<endl; */
    if(s!=mid_idx)
      iter_swap(A.begin()+s,A.begin()+mid_idx);
  
  int i=s+1;
  int j=s+1;
  auto pivot= A[s];

  while(j<f)
  {
    if(A[j]<pivot)
    {
      iter_swap(A.begin()+i, A.begin()+j);
      i++;
    }
    j++;
  }

  //final swap of the pivot
  iter_swap(A.begin()+s, A.begin()+i-1);

  //pivot position
  pivotPos = i-1;
  return (f-s-1);
}

int Quick_Sort_partial(vec &A, int s, int f){
  //quick sort partial array
  
  int pos;
  int n= A.size();

  if((f-s)<=1)
    return 0;

  int comp= partition(A,s,f,pos);



  return comp+ Quick_Sort_partial(A,s,pos)+ Quick_Sort_partial(A,pos+1,f);
}

int Quick_Sort(vec &A){
  
  /* Function to quick sort the array whith a determnistic choice for the pivot
   * f : first
   * l : last
   * m : median
   */

  auto comp=Quick_Sort_partial(A,0,A.size());
  return comp;
}
