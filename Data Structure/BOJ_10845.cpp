#include <iostream>
#include <string>

using namespace std;

const int MAX_QUEUE_SIZE = 10000;

template <typename T>
class Queue
{	
public:
	void push(T param);
	T pop();
	int isEmpty();
	int isFull();
	T getFront();
	T getBack();
	int size();
	
private:
	int front = 0;
	int rear = 0;
	T data[MAX_QUEUE_SIZE];
};

template<typename T>
int Queue<T>::isFull()
{
	if((rear+1) % MAX_QUEUE_SIZE == front)
		return 1;
	return 0;
}

template<typename T>
int Queue<T>::isEmpty()
{
	if(rear == front)
		return 1;
	return 0;
}

template<typename T>
void Queue<T>::push(T param)
{
	rear = (rear+1) % MAX_QUEUE_SIZE;
	data[rear] = param;
}

template<typename T>
T Queue<T>::pop()
{
	front = (front +1) % MAX_QUEUE_SIZE;
	return data[front];
}

template<typename T>
T Queue<T>::getFront()
{
	return data[front+1];
}

template<typename T>
T Queue<T>::getBack()
{
	return data[rear];
}

template<typename T>
int Queue<T>::size()
{
	if(isFull())
		return MAX_QUEUE_SIZE-1;
	if(isEmpty())
		return 0;
	
	int size = rear - front;
	
	if(size < 0)
		size + MAX_QUEUE_SIZE;
	
	return size;
}

	
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	Queue<int> my_queue;
	
	int input_count; 
	cin >> input_count; 
	
	
	while(input_count--)
	{
		string instr;	
		cin >> instr; 
	
		if (instr == "push")
		{
			int x;
			cin >> x;
		
			my_queue.push(x);
		}
		else if (instr == "pop")
		{
			if(my_queue.isEmpty())
				cout << -1 << '\n';
			else
				cout << my_queue.pop() << '\n';
		}
		else if (instr == "size")
		{
			cout << my_queue.size() << '\n';
		}
		else if (instr == "empty")
		{
			cout << my_queue.isEmpty() << '\n';
		}
		else if (instr == "front")
		{
			if(my_queue.isEmpty())
				cout << -1 << '\n';
			else 
				cout << my_queue.getFront() << '\n';
		}
		else if (instr == "back")
		{
			if(my_queue.isEmpty())
				cout << -1 << '\n';
			else 
				cout << my_queue.getBack() << '\n';
		}
		
	}
}