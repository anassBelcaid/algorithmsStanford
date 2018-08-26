#include "gtest/gtest.h"
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
using std::is_heap;
using std::make_heap;
using std::make_pair;

#include "single_shortest_paths.hpp"

TEST (correctness, heap1) { 
 /** simple work on heaps on c++
  */
 vector<int> A{1,4,8,4,2,5};
 EXPECT_EQ(is_heap(A.begin(),A.end()), false);

 //heapify
 auto my_comp=[](int a, int b){return a>b;};
 make_heap(A.begin(),A.end(),my_comp);

 EXPECT_EQ(is_heap(A.begin(),A.end(),my_comp),true);

 for(auto v: A)
   cout<<v<<" ";
 cout<<endl;
}


TEST (correctness, pairs) { 
   using edge = std::pair<int,int>; 
   auto my_comp = [](edge A, edge B){ return A.second>B.second;};

   vector<edge> B;
   B.push_back(make_pair(1,4));
   B.push_back(make_pair(2,5));
   B.push_back(make_pair(3,1));
   B.push_back(make_pair(4,0));

   make_heap(B.begin(),B.end(),my_comp);
   EXPECT_EQ(is_heap(B.begin(),B.end(),my_comp),true);

   for(auto v: B)
     cout<<v.first<<"->"<<v.second<<endl;

}

TEST (correctness, simpleCase) { 

    Graph  G("example1.txt");
    single_shortest_paths paths(G);
    paths.compute_paths(0);
    auto dis= paths.getdistances();
    EXPECT_EQ(dis[0],0);
    EXPECT_EQ(dis[1],3);
    EXPECT_EQ(dis[2],5);
    EXPECT_EQ(dis[3],9);
    EXPECT_EQ(dis[4],11);

}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


