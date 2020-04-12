// Copyright 2020 Roger Peralta Aranibar
#include "pointer_machine/directed_graph.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace ADE {
namespace Tests {
class NodeTest : public ::testing::Test {
 protected:
  NodeTest() {}
  virtual ~NodeTest() {}

  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(NodeTest, constructor_createsEmptyList) {
  EXPECT_THAT(10, ::testing::Eq(size_t(0)));
}

}  // namespace Tests
}  // namespace ADE
