#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

const int MAX_DEQUE_SIZE = 1000000;

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
	
	string input_str; 
	string output_str;
	Deque<char> my_deque;
	
	getline(cin, input_str);
	
	bool is_tag_check(false);
	
	for(char ch : input_str)
	{
		if(ch == '<')
		{
			while(!my_deque.isEmpty())
			{
				output_str += my_deque.pop_back();	
			}
			is_tag_check = true;
			my_deque.push_back(ch);
		}
		else if(ch == '>')
		{
			is_tag_check = false;
			my_deque.push_back(ch);
			while(!my_deque.isEmpty())
			{
				output_str += my_deque.pop_front();	
			}
		}
		else if(isspace(ch) && is_tag_check == false)
		{	
			while(!my_deque.isEmpty())
			{
				output_str += my_deque.pop_back();	
			}
			output_str += ch;
		}
		else 
		{
			my_deque.push_back(ch);	
		}
	}
	
	while(!my_deque.isEmpty())
	{
		output_str += my_deque.pop_back();	
	}
	
	cout << output_str << endl;

}