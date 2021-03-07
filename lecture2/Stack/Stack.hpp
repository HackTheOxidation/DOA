#pragma once

template <typename T>
class Stack {
	public:
		virtual T top() = 0;
		virtual void push(const T& item) = 0;
		virtual T pop() = 0;
		virtual bool isEmpty() = 0;
		virtual ~Stack() {}
};

