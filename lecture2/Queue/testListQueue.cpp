#include "ListQueue.hpp"
#include <iostream>
#include <gtest/gtest.h>

TEST(ListQueueTest, PushEmpty) {
	ListQueue<int> queue;
	queue.push(1);
	ASSERT_FALSE(queue.isEmpty());
	ASSERT_EQ(1, queue.front());
}

TEST(ListQueueTest, PushNonEmpty) {
	ListQueue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	ASSERT_EQ(1, queue.front());
}

TEST(ListQueueTest, PopNonEmpty) {
	ListQueue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.pop();
	ASSERT_EQ(2, queue.front());
}

int main(int argc, char **argv) { 
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

