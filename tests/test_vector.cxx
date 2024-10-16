#include <gtest/gtest.h>
#include <string>

#include "vector.h"

using std::string;

TEST(SampleTest, AssertionTrue) {
  string lhs = "not implemented";
  string rhs = "implemented";

  EXPECT_STREQ(lhs.c_str(), rhs.c_str());
}
