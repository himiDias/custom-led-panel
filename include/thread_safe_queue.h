#ifndef THREADSAFEQ_H
#define THREADSAFEQ_H

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <optional>

template <typename T>
class ThreadSafeQ {
	private:
	
	std::queue<T> m_queue;
	
	std::mutex m_mutex;
	
	std::condition_variable m_cond;
	
	public:
	
	void push(T item)
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		
		m_queue.push(item);
		std::cout << "TSQ - " << item << " PUSHED" << std::endl;
		
		m_cond.notify_one();
	}
	
	T pop()
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		
		m_cond.wait(lock,[this]() {return !m_queue.empty(); });
		
		T item = m_queue.front();
		m_queue.pop();
		std::cout << "TSQ - " << item << " POPPED" << std::endl;
		
		return item;
	}
	
	//for non-blocking pop, needed for panel
	std::optional<T> nonBlockPop()
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		if (m_queue.empty()) return std::nullopt;
		
		T item = m_queue.front();
		m_queue.pop();
		std::cout << "TSQ - " << item << " POPPED" << std::endl;
		
		return item;
	}
	
};

#endif
