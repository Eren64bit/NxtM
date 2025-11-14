#include <gtest/gtest.h> // google test lib
#include <iostream>
//#include <nxtm/vector3.hpp>


TEST(Vector3Test, VectorConstructor) {
	nxtm::Vector3 v1(1.0f, 2.0f, 3.0f);
	
	EXPECT_FLOAT_EQ(v.x, 1.0f);

	EXPECT_FLOAT_EQ(v.y, 2.0f);

	EXPECT_FLOAT_EQ(v.z, 3.0f);

	std::stringstream ss;

	ss << v1;

	EXPECT_EQ(ss.str(), "Vector3(1, 2, 3)");
}
