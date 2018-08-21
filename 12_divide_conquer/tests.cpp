#include "gtest/gtest.h"
#include "inversions.hpp"
#include <algorithm>
using std::random_shuffle;
using std::for_each;

#include <iostream>
using std::cout;
using std::endl;

vec random_vector(size_t n)
{
  //creating the array
  vec A(n);

  for(auto i=1;i<=n;i++)
    A[i]=i;
  
  //shuffle
  random_shuffle(A.begin(),A.end());

  return A;
}

TEST (Correctness, babyTest) { 
    vec A{6,3,2,5,4,1};


    EXPECT_EQ(brute_force_invversion(A),11);
}

TEST (Correctness, unit) { 
    auto A=random_vector(1000);
    auto val1 = brute_force_invversion(A);
    auto val2 = count_sort(A);
    /* for_each(A.begin(),A.end(),[](int a){cout<<a<<" ";}); */
    /* cout<<endl; */
    EXPECT_EQ(val1,val2);
}

int main(int argc, char **argv) {
  srand(0); 
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

