#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 15000;
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
	
	int getTop()
	{
		return data[top];
	}
	
private: 
	int top;
	T data[MAX_STACK_SIZE+1];
};

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	Stack<int> my_stack;
	
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
		
			my_stack.push(x);
		}
		else if (instr == "pop")
		{
			if(my_stack.isEmpty())
				cout << -1 << '\n';
			else
				cout << my_stack.pop() << '\n';
		}
		else if (instr == "size")
		{
			cout << my_stack.size() << '\n';
		}
		else if (instr == "empty")
		{
			cout << my_stack.isEmpty() << '\n';
		}
		else if (instr == "top")
		{
			if(my_stack.isEmpty())
				cout << -1 << '\n';
			else 
				cout << my_stack.getTop() << '\n';
		}
	}
	return 0;

}