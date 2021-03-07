#include "ListStack.hpp"
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class StackUnitTest : public testing::Test {
	protected:
		void SetUp() {
			uut = new ListStack<int>();
		}

		void TearDown() {
			delete uut;
		}

		Stack<int>* uut;
};

TEST_F(StackUnitTest, Ctor_StackEmpty) {
	ASSERT_TRUE(uut->isEmpty());
}

TEST_F(StackUnitTest, Push_StackNotEmpty) {
	uut->push(2);
	ASSERT_FALSE(uut->isEmpty());
}

TEST_F(StackUnitTest, Push_StackTopCorrect) {
	uut->push(2);
	ASSERT_EQ(uut->top(), 2);
}

TEST_F(StackUnitTest, Push_StackTopCorrect2) {
	uut->push(2);
	uut->push(1);
	ASSERT_EQ(uut->top(), 1);
}

TEST_F(StackUnitTest, PushPop_StackEmpty) {
	uut->push(2);
	int ret = uut->pop();
	ASSERT_TRUE(uut->isEmpty());
	ASSERT_EQ(ret, 2);
}

TEST_F(StackUnitTest, Pop_StackEmpty) {
	ASSERT_THROW(uut->pop(), std::out_of_range);
}

TEST_F(StackUnitTest, Top_StackEmpty) {
	ASSERT_THROW(uut->top(), std::out_of_range);
}

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
