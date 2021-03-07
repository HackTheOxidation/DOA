#include "HashMap.hpp"
#include <iostream>
#include <string>
#include <gtest/gtest.h>

using namespace std;

class HashMapUnitTest : public testing::Test {
	protected:
		void SetUp() {
			uut = new HashMap<int, string>();
		}

		void TearDown() {
			delete uut;
		}

		HashMap<int, string>* uut;
};

TEST_F(HashMapUnitTest, CheckEmptyOnCreation) {
	ASSERT_EQ(uut->getSize(), 0);
	ASSERT_EQ(uut->getCapacity(), 10);
	ASSERT_EQ(uut->getLoadFactor(), 0);
}

TEST_F(HashMapUnitTest, InsertNoCollision) {
	uut->insert(8, "Eight");
	ASSERT_TRUE(uut->search(8));
	ASSERT_NE(uut->getLoadFactor(), 0);
}

TEST_F(HashMapUnitTest, InsertWithCollision) {
	uut->insert(0, "Zero");
	uut->insert(10, "Ten");
	ASSERT_TRUE(uut->search(10));
	ASSERT_GT(uut->getLoadFactor(), 0.1);
}

TEST_F(HashMapUnitTest, RemoveAfterInsertion) {
	uut->insert(8, "Eight");
	ASSERT_TRUE(uut->search(8));
	uut->remove(8);
	ASSERT_FALSE(uut->search(8));
}

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
