class Queue {
	stack<int> s;
	stack<int> queueStack;
public:
	// Push element x to the back of queue.
	void push(int x) {
		s.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (queueStack.empty()) {
			while (!s.empty()) {
				queueStack.push(s.top());
				s.pop();
			}
		}
		if (!queueStack.empty()) {
			queueStack.pop();
		}
	}

	// Get the front element.
	int peek(void) {
		if (queueStack.empty()) {
			while (!s.empty()) {
				queueStack.push(s.top());
				s.pop();
			}
		}
		return queueStack.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return queueStack.empty() && s.empty();
	}
};