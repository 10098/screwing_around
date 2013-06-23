#include "queue.h"
#include <stdexcept>
#include <cstring>

Queue::Queue(unsigned size):
	m_count(0), m_capacity(size), m_front(0), m_back(0)
{
	m_q = new int[size];
}

Queue::~Queue()
{
	delete[] m_q;
}

void Queue::push(int value)
{
	if(m_count >= m_capacity) {
		resize(m_capacity * 2);
	}
	m_q[m_front] = value;
	m_front = (m_front + 1) % m_capacity;
	m_count++;
}

int Queue::pop()
{
	if(m_count <= 0)
		throw std::runtime_error("a");
	int rv = top();
	m_count--;
	m_back++;
	return rv;
}

int Queue::top() const
{
	if(m_count <= 0)
		throw std::runtime_error("a");
	return m_q[m_back];
}

void Queue::resize(int new_capacity)
{
	int *new_q = new int[new_capacity];
	memcpy(new_q, &m_q[m_back], sizeof(int) * (m_capacity - m_back));
	if(m_front == m_back)
		memcpy(&new_q[m_capacity - m_back], m_q, sizeof(int) * m_front);
	delete[] m_q;
	m_q = new_q;
	m_back = 0;
	m_front = m_capacity;
	m_capacity = new_capacity;
}

