#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX_STACK_SIZE = 1001000;

template <typename T> 
class Stack
{
public:
	Stack() {top = -1; }
	bool isEmpty() {return top == -1; }
	bool isFull() {return top == MAX_STACK_SIZE-1;}
		
	void push(T param){
		if(isFull()){
			return;
		}
		data[++top] = param;
	}
	
	T pop(){
		return data[top--];
	}
	
	int size()
	{
		return top+1;
	}
	
	T peek()
	{
		return data[top];
	}
	
private: 
	int top;
	T data[MAX_STACK_SIZE+1];
};

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_count;
	cin >> input_count;
	
	Stack<int> my_stack;
	int* input_arr = new int[input_count];
	int* result_arr = new int[input_count];

	for(int i=0; i<input_count; i++)
	{
		cin >> input_arr[i];
	}
	
	
	for(int i=input_count-1; i>=0; i--)
	{
		while(!my_stack.isEmpty())
		{
			if(input_arr[i] < my_stack.peek())
			{
				result_arr[i] = my_stack.peek();
				break;
			}
			else
				my_stack.pop();
		}
			
		if(my_stack.isEmpty())
			result_arr[i] = -1;
		
		my_stack.push(input_arr[i]);
	}
	
	
	for(int i=0; i<input_count; i++)
	{
		if(i != input_count-1)
			cout << result_arr[i] << " ";
		else
			cout << result_arr[i] << endl;
	}
	
	delete[] input_arr;
	delete[] result_arr;
	
}