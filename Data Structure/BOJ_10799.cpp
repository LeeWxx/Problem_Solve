#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX_STACK_SIZE = 100000;

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
	
private: 
	int top;
	T data[MAX_STACK_SIZE+1];
};

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string input_str;
	Stack<char> my_stack;
	int count(0);
	
	cin >> input_str;
	
	for(int i=0; i<input_str.size(); i++)
	{
		if(input_str[i] == '(')
		{
			if(input_str[i+1] == ')')
			{
				count += my_stack.size();
			}
			else
			{
				my_stack.push(input_str[i]);
			}
		}
		else 
		{
			if(input_str[i-1] == ')')
			{
				my_stack.pop();
				count++;	
			}
		}
	}
	
	cout << count << endl;
}