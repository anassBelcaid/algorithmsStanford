#include "gtest/gtest.h"
#include <algorithm>
#include "kargerCut.h"

using std::random_shuffle;
using std::for_each;

#include <iostream>
using std::cout;
using std::endl;

TEST (correctness, baby1) { 
    kargerCut A("baby.txt");
    auto cut = A.min_cut();
    EXPECT_EQ(cut,3);
}
TEST (correctness, baby2) { 
    kargerCut A("baby2.txt");
    auto cut = A.min_cut();
    EXPECT_EQ(cut,2);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

