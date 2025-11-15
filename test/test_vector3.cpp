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
  float x = 1.0f;
  nxtm::Vector3f result = v1 + v2;
  nxtm::Vector3f result_scalar = v1 + x;
  v1 += 6.0f;

  // v1 + v2
  EXPECT_FLOAT_EQ(result.x, 7.5f);

  EXPECT_FLOAT_EQ(result.y, 9.5f);

  EXPECT_FLOAT_EQ(result.z, 14.5f);

  // v1 + x
  EXPECT_FLOAT_EQ(result_scalar.x, 3.5f);

  EXPECT_FLOAT_EQ(result_scalar.y, 4.5f);

  EXPECT_FLOAT_EQ(result_scalar.z, 5.5f);

  // v1 += 6.0f
  EXPECT_FLOAT_EQ(v1.x, 8.5f);

  EXPECT_FLOAT_EQ(v1.y, 9.5f);

  EXPECT_FLOAT_EQ(v1.z, 10.5f);

}

TEST(Vector3Test, VectorSub)
{
  nxtm::Vector3f v1(2.5f, 3.5f, 4.5f);
  nxtm::Vector3f v2(0.5f, 1.5f, 2.5f);
  float x = 1.0f;
  nxtm::Vector3f result1 = v1 - v2;
  nxtm::Vector3f result_scalar = v1 - x;
  v1 -= 6.0f;
  
  // v1- v2
  EXPECT_FLOAT_EQ(result1.x, 2.0f);

  EXPECT_FLOAT_EQ(result1.y, 2.0f);

  EXPECT_FLOAT_EQ(result1.z, 2.0f);

  // v1 - x
  EXPECT_FLOAT_EQ(result_scalar.x, 1.5f);

  EXPECT_FLOAT_EQ(result_scalar.y, 2.5f);

  EXPECT_FLOAT_EQ(result_scalar.z, 3.5f);

  // v1 -= 6.0f
  EXPECT_FLOAT_EQ(v1.x, -3.5f);

  EXPECT_FLOAT_EQ(v1.y, -2.5f);

  EXPECT_FLOAT_EQ(v1.z, -1.5f);
}

TEST(Vector3Test, VectorMult)
{
  nxtm::Vector3f v1(2.2f, 2.2f, 2.2f);
  nxtm::Vector3f v2(2.0f, 3.0f, 4.0f);
  float x = 2.0f;
  nxtm::Vector3f result = v1 * v2;
  nxtm::Vector3f result_scalar = v1 * x;
  v1 *= 6.0f;

  // v1 * v2
  EXPECT_FLOAT_EQ(result.x, 4.4f);

  EXPECT_FLOAT_EQ(result.y, 6.6f);

  EXPECT_FLOAT_EQ(result.z, 8.8f);

  // v1 * x
  EXPECT_FLOAT_EQ(result_scalar.x, 4.4f);

  EXPECT_FLOAT_EQ(result_scalar.y, 4.4f);

  EXPECT_FLOAT_EQ(result_scalar.z, 4.4f);

  // v1 *= 6.0f
  EXPECT_FLOAT_EQ(v1.x, 13.2f);

  EXPECT_FLOAT_EQ(v1.y, 13.2f);

  EXPECT_FLOAT_EQ(v1.z, 13.2f);
}

TEST(Vector3Test, VectorDivide)
{
  nxtm::Vector3f v1(8.0f, 10.0f, 12.0f);
  nxtm::Vector3f v2(2.0f, 5.0f, 6.0f);
  float x = 2.0f;
  nxtm::Vector3f result1 = v1 / v2;
  nxtm::Vector3f result_scalar = v1 / x;
  v1 /= 1.0f;

  //TODO:add 0 divide

  // v1 / v2
  EXPECT_FLOAT_EQ(result1.x, 4.0f);

  EXPECT_FLOAT_EQ(result1.y, 2.0f);

  EXPECT_FLOAT_EQ(result1.z, 2.0f);

  // v1 / x
  EXPECT_FLOAT_EQ(result_scalar.x, 4.0f);

  EXPECT_FLOAT_EQ(result_scalar.y, 5.0f);

  EXPECT_FLOAT_EQ(result_scalar.z, 6.0f);

  // v1 /= 6.0f
  EXPECT_FLOAT_EQ(v1.x, 8.0f);

  EXPECT_FLOAT_EQ(v1.y, 10.0f);

  EXPECT_FLOAT_EQ(v1.z, 12.0f);
}

TEST(Vector3Test, VectorDot)
{
  nxtm::Vector3f v1(2.0f, 3.0f, 4.0f);
  nxtm::Vector3f v2(3.0f, 4.0f, 5.0f);
  float result = v1.dot(v2);

  EXPECT_FLOAT_EQ(result, 38.0f);

}

TEST(Vector3Test, VectorLenght) 
{
  nxtm::Vector3f v1(1.0f, 2.0f, 3.0f);
  auto len = v1.length();

  EXPECT_FLOAT_EQ(len, 3.7416575f);
}

TEST(Vector3Test, VectorLenghtSquare) 
{
  nxtm::Vector3f v1(1.0f, 2.0f, 3.0f);
  auto len = v1.length_square();

  EXPECT_FLOAT_EQ(len, 14.0f);
}

TEST(Vector3Test, VectorCross) 
{
  nxtm::Vector3f v1(1.0f, 2.0f, 2.0f);
  nxtm::Vector3f v2(3.0f, 0.0f, 4.0f);
  nxtm::Vector3f result = v1.cross(v2);

  EXPECT_FLOAT_EQ(result.x, 8.0f);

  EXPECT_FLOAT_EQ(result.y, 2.0f);

  EXPECT_FLOAT_EQ(result.z, -6.0);
}

TEST(Vector3Test, VectorNormalized)
{
  nxtm::Vector3f v1(2.0f, 1.0f, 3.0f);
  auto result = v1.normalized();

  EXPECT_FLOAT_EQ(result.x, 0.53452247f);

  EXPECT_FLOAT_EQ(result.y, 0.26726124f);

  EXPECT_FLOAT_EQ(result.z, 0.80178368f);
}