#include <iostream>
#include <string>

using namespace std;

const int MAX_DEQUE_SIZE = 100000;

template<typename T>
class Deque
{
public: 
	void push_front(T param);
	void push_back(T param);
	T pop_front();
	T pop_back();
	int isEmpty();
	int isFull();
	T getFront();
	T getBack();
	int size();
	
private:
	int front = 0;
	int rear = 0;
	T data[MAX_DEQUE_SIZE];
};

template<typename T>
int Deque<T>::isFull()
{
	if((rear+1) % MAX_DEQUE_SIZE == front)
		return 1;
	return 0;
}

template<typename T>
int Deque<T>::isEmpty()
{
	if(rear == front)
		return 1;
	return 0;
}

template<typename T>
void Deque<T>::push_back(T param)
{
	if(isFull())
		return;
	rear = (rear+1) % MAX_DEQUE_SIZE;
	data[rear] = param;
}

template<typename T>
void Deque<T>::push_front(T param)
{
	if(isFull())
		return;
	data[front] = param;
	front = (front-1+MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

template<typename T>
T Deque<T>::pop_back()
{
	int ret = data[rear];
	rear = (rear-1+MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	return ret;
}

template<typename T>
T Deque<T>::pop_front()
{
	front = (front+1+MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	int ret = data[front];
	return ret;
}

template<typename T>
T Deque<T>::getFront()
{
	return data[(front+1)%MAX_DEQUE_SIZE];
}

template<typename T>
T Deque<T>::getBack()
{
	return data[rear];
}

template<typename T>
int Deque<T>::size()
{
	if(isEmpty())		
		return 0;
	
	if(isFull())
		return MAX_DEQUE_SIZE-1;
	
	int size = rear-front;
	if(size < 0)
		size = size + MAX_DEQUE_SIZE;
	return size;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_count; 
	cin >> input_count; 
	
	Deque<int> my_deque;
	while(input_count--)
	{
		string instr;	
		cin >> instr; 
	
		if (instr == "push_back")
		{
			int x;
			cin >> x;
		
			my_deque.push_back(x);
		}
		else if (instr == "push_front")
		{
			int x;
			cin >> x;
		
			my_deque.push_front(x);
		}
		else if (instr == "pop_front")
		{
			if(my_deque.isEmpty())
				cout << -1 << '\n';
			else
				cout << my_deque.pop_front() << '\n';
		}
		else if (instr == "pop_back")
		{
			if(my_deque.isEmpty())
				cout << -1 << '\n';
			else
				cout << my_deque.pop_back() << '\n';
		}
		else if (instr == "size")
		{
			cout << my_deque.size() << '\n';
		}
		else if (instr == "empty")
		{
			cout << my_deque.isEmpty() << '\n';
		}
		else if (instr == "front")
		{
			if(my_deque.isEmpty())
				cout << -1 << '\n';
			else 
				cout << my_deque.getFront() << '\n';
		}
		else if (instr == "back")
		{
			if(my_deque.isEmpty())
				cout << -1 << '\n';
			else 
				cout << my_deque.getBack() << '\n';
		}
	}
	
}