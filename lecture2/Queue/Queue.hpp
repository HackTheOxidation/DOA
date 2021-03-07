
template<class T>
class Queue {
	public:
		virtual T& front() = 0;
		virtual bool isEmpty() const = 0;
		virtual void pop() = 0;
		virtual void push(const T& x) = 0;
		virtual ~Queue() {}
};
