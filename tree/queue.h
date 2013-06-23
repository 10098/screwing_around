#pragma once

class Queue
{
public:
	explicit Queue(unsigned size = 10);
	~Queue();

	void push(int v);
	int pop();
	int top() const;
	int count() const { return m_count; }
private:
	void resize(int new_capacity);

	int m_count;
	int m_capacity;
	int *m_q;
	int m_front;
	int m_back;
};

