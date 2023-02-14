#include <iostream>
#include <string>

using namespace std;

const int MAX_QUEUE_SIZE = 1000000;

template <typename T>
class Queue
{	
public:
	void push(T param);
	T pop();
	int isEmpty();
	int isFull();
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

void josephus(int N, int K)
{
	Queue<int> my_queue;
	Queue<int> output_queue;
	
	for(int i = 1; i<= N; i++)
		my_queue.push(i);
	
	
	while(!my_queue.isEmpty())
	{
		for(int i =0; i<K-1; i++)
		{
			int elem = my_queue.pop();
			my_queue.push(elem);
		}
		
		int elem = my_queue.pop();
		output_queue.push(elem);
	}
	
	cout << "<";
	while(!output_queue.isEmpty())
	{
		if(output_queue.size() == 1){
			cout << output_queue.pop();
			break;
		}
		cout << output_queue.pop() << ", ";
	}
	cout << ">" << endl;
}

	
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int peopleNum, countNum;
	
	cin >> peopleNum;
	cin >> countNum;
	
	josephus(peopleNum, countNum);
}