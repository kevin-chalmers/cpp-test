#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(SampleTest, Equal){
    EXPECT_EQ(42, 42);
}

TEST(ContainerComparison, Equal){
    const std::vector<int> a(2, 1);
    const std::vector<int> b(2, 1);

    EXPECT_THAT(a, testing::ContainerEq(b));
    EXPECT_THAT(a, testing::ContainerEq(b)); // doesn't work either
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}