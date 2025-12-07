#include <gtest/gtest.h>

TEST(DummyTest, BasicAssertions) {
  EXPECT_EQ(1 + 1, 2);
  EXPECT_TRUE(true);
  EXPECT_NE(5, 10);
}

TEST(StringTest, Compare) {
  std::string s = "hello";
  EXPECT_EQ(s, "hello");
  EXPECT_NE(s, "world");
}
