#include "gtest/gtest.h"
#include "quickSort.hpp"
using std::is_sorted;
using std::random_shuffle;

TEST (correctness, Numberinversion) { 
  vec A{1,3,1,3,2,3};
  int pos;
  EXPECT_EQ(partition(A,0,6,pos),5);
  EXPECT_EQ(partition(A,0,3,pos),2);
  cout<<"pivot position ="<<pos<<endl;
}

TEST (correctness, swaping) { 
  /* Testing swapping with iter_swap */
    vec A{1,2};

    iter_swap(A.begin(), A.begin()+1);
    EXPECT_EQ(A[0],2);
    EXPECT_EQ(A[1],1);
}

TEST(partition, partition){
  vec A{5,1,4,7,8,2,4,13,10,0};
  int pos;
  auto p = partition(A,0,10,pos);

  //expect the equality
  EXPECT_EQ(p,9);
}

TEST (correctness, sorting) {

    vec A{4,3,2,1,3,4,5,3,1,4,9,3,1,3,8,31,32,32,13};

    auto comp= Quick_Sort(A);
  
    EXPECT_EQ(is_sorted(A.begin(),A.end()),true);
}

TEST (correctness, numberComp) { 
  
  vec A{3,2,8,5,1,4,7,6};

  auto comp = Quick_Sort(A);

  EXPECT_EQ(is_sorted(A.begin(),A.end()),true);
}

TEST (correctness, ShuffleSort) { 

    /* auto n=1E3; */
  auto n =20;
    vec A(n);
    for(int i=0;i<n;i++)
      A[i]=i;
    random_shuffle(A.begin(),A.end());
    Quick_Sort(A);
    EXPECT_EQ(is_sorted(A.begin(),A.end()),true);
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

