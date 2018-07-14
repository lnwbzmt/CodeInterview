#include <string.h>
#include <stack>
#include <iostream>
#include <vector>
#include <queue>
#include <exception>
using namespace std;

//自己写的 
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {     
        int p;
        if(stack2.empty() == 0)
        {
            p = stack2.top();
            stack2.pop();
        }
        else
        {
            while(stack1.empty() == 0)
            {
            	p = stack1.top();
                stack2.push(p);
                stack1.pop();
            }
            stack2.pop();

        }
        return p;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};



//书上的
template <typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);
	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;	
};

template<typename T> void CQueue<T>::appendTail(const T &element)
{
	stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead()
{
	if(stack2.size() <= 0)
	{
		while(stack1.size() <= 0)
		{
			T &data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
//	if(stack2.size() == 0)
//		throw new exception("queue is empty.");
	T head = stack2.top();
	stack2.pop();
	return head;
}

//用两个栈实现队列 
template <typename T> class CStack
{
public:
	CStack(void);
	~CStack(void);
	void push(const T& node);
	T pop();
private:
	queue<T> queue1;
	queue<T> queue2;
};

template<typename T> CStack<T>::CStack()
{
	
}template<typename T> CStack<T>::~CStack()
{
	
}
template<typename T> void CStack<T>::push(const T& node)
{
	if(queue1.empty() == 0)
		queue1.push(node);
	else
		queue2.push(node);
}

template<typename T> T CStack<T>::pop()
{
	T t;
//	if(stack1.empty() && stack2.empty())
//		throw new exception("stack is empty"); 
	if(queue1.empty() == 0)
	{
		while(queue1.size() > 0)
		{
			t = queue1.front();
			
			if(queue1.size() > 1)
				queue2.push(t);
			queue1.pop();
		}
	}
	else
	{
		while(queue2.size() > 0)
		{
			t = queue2.front();
			
			if(queue2.size() > 1)
				queue1.push(t);
			queue2.pop();
		}
	}
	return t;
}

int main()
{
	CStack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	return 0;
} 