#include "LinkedList.hpp"
#include "VectorList.hpp"
#include <iostream>
#include <exception>
#include <string>
#include <gtest/gtest.h>

TEST(LinkedListTest, RemoveHead) {
	Node<int> * node = new Node<int>{1, nullptr};
    	LinkedList<int> * list = new LinkedList<int>(node);
	list->headRemove();
    	ASSERT_EQ(0, list->length());
}

TEST(LinkedListTest, InsertHead) {
	Node<int> * node = new Node<int>{1, nullptr};
    	LinkedList<int> * list = new LinkedList<int>(node);
	list->headInsert(0);
    	ASSERT_EQ(2, list->length());
}

TEST(LinkedListTest, At) {
	Node<int> * node = new Node<int>{1, nullptr};
    	LinkedList<int> * list = new LinkedList<int>(node);
	ASSERT_EQ(1, list->at(0));	
}

TEST(LinkedListTest, AtError) {
	Node<int> * node = new Node<int>{1, nullptr};
    	LinkedList<int> * list = new LinkedList<int>(node);
	ASSERT_THROW(list->at(2), out_of_range);
}


TEST(VectorListTest, RemoveHead) {
	VectorList<int> vlist;
	vlist.headInsert(1);
	vlist.headInsert(2);
	vlist.headInsert(3);
	vlist.headRemove();
	ASSERT_EQ(2, vlist.at(0));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
