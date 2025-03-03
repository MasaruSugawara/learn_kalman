#include <gtest/gtest.h>

int sampleFunc(int a, int b) {
    return a + b;
}

TEST(sampleFuncTest, BasicTest) {
    EXPECT_EQ( sampleFunc(3, 4), 7); //GOOD
//    EXPECT_EQ( sampleFunc(1, 1), 3); //NG!
}
