#include <gtest/gtest.h> // google test lib
#include <iostream>
#include "../include/nxtm/vector3.hpp"

TEST(Vector3Test, VectorConstructor)
{
  nxtm::Vector3f v1(1.0f, 2.0f, 3.0f);

  EXPECT_FLOAT_EQ(v1.x, 1.0f);

  EXPECT_FLOAT_EQ(v1.y, 2.0f);

  EXPECT_FLOAT_EQ(v1.z, 3.0f);

  std::stringstream ss;

  ss << v1;

  EXPECT_EQ(ss.str(), "Vector3(1, 2, 3)");
}

TEST(Vector3Test, VectorSum)
{
  nxtm::Vector3f v1(2.5f, 3.5f, 4.5f);
  nxtm::Vector3f v2(5.0f, 6.0f, 10.0f);
  nxtm::Vector3f result = v1 + v2;

  EXPECT_FLOAT_EQ(result.x, 7.5f);

  EXPECT_FLOAT_EQ(result.y, 9.5f);

  EXPECT_FLOAT_EQ(result.z, 14.5f);
}

TEST(Vector3Test, VectorSub)
{
  nxtm::Vector3f v1(2.5f, 3.5f, 4.5f);
  nxtm::Vector3f v2(0.5f, 1.5f, 2.5f);
  nxtm::Vector3f result1 = v1 - v2;
  nxtm::Vector3f result2 = v2 - v1;

  EXPECT_FLOAT_EQ(result1.x, 2.0f);

  EXPECT_FLOAT_EQ(result1.y, 2.0f);

  EXPECT_FLOAT_EQ(result1.z, 2.0f);

  EXPECT_FLOAT_EQ(result2.x, -2.0f);

  EXPECT_FLOAT_EQ(result2.y, -2.0f);

  EXPECT_FLOAT_EQ(result2.z, -2.0f);
}

TEST(Vector3Test, VectorMult)
{
  nxtm::Vector3f v1(2.2f, 2.2f, 2.2f);
  nxtm::Vector3f v2(2.0f, 3.0f, 4.0f);
  nxtm::Vector3f result = v1 * v2;

  EXPECT_FLOAT_EQ(result.x, 4.4f);

  EXPECT_FLOAT_EQ(result.y, 6.6f);

  EXPECT_FLOAT_EQ(result.z, 8.8f);
}

TEST(Vector3Test, VectorDivide)
{
  nxtm::Vector3f v1(8.0f, 10.0f, 12.0f);
  nxtm::Vector3f v2(2.0f, 5.0f, 6.0f);

  nxtm::Vector3f result1 = v1 / v2;
  nxtm::Vector3f result2 = v2 / v1;

  EXPECT_FLOAT_EQ(result1.x, 4.0f);

  EXPECT_FLOAT_EQ(result1.y, 2.0f);

  EXPECT_FLOAT_EQ(result1.z, 2.0f);
}
