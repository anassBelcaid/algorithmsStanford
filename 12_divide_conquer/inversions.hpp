#ifndef INVERSIONS_HPP_FRHAJ1GM
#define INVERSIONS_HPP_FRHAJ1GM
#include <vector>
using vec=std::vector<int>;

#include <iostream>
using std::cout;
using std::endl;



size_t brute_force_invversion(const vec & A)
{
  int n = A.size();

  size_t count{0};

  for(int i = 0 ; i < n ; i++)
    for(int j = i+1; j < n; j++)
      if(A[j]<A[i])
        count++;

  return count;
}


vec merge(const vec & A, const vec &B, size_t & invs)
{
  //Function to merge the sorted arrays A and B and count the number of invs
  //

  size_t n = A.size();
  size_t m = B.size();
  vec C(n+m);

  size_t i=0; size_t j =0; size_t k=0;

  while(i< n && j <m)
  {
    if(A[i]<=B[j])
      C[k++]=A[i++];
    else
    {
      C[k++]=B[j++];
      invs+=n-i;
    }
  }

  //finishing the merge
  while(i<n)
    C[k++]=A[i++];
  while(j<m)
    C[k++]=B[j++];

  return C;
}
size_t count_sort(vec & A)
{
  /* Count the number of inversions and sor the array
   */

  /* cout<<"Received ="<<endl; */
  /* for_each(A.begin(),A.end(), [](int a){cout<<a<<" ";}); */
  /* cout<<endl; */
  
  int n =A.size();
  
  //base case
  if(n==1 || n==0)
    return 0;

  //resursion
  auto mid= n/2;

  vec left(A.begin(),A.begin()+mid);
  vec right(A.begin()+mid, A.end());

  //sorting the arrays
  auto left_i  = count_sort(left);
  auto right_i = count_sort(right);

  size_t invs=0;
  auto sorted= merge(left, right, invs);

  //copy the sort
  A= sorted;
  return left_i + right_i + invs;
}

#endif /* end of include guard: INVERSIONS_HPP_FRHAJ1GM */
