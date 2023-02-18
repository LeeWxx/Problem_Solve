#include <iostream>
#include <string>

using namespace std;

const int MAX_STACK_SIZE = 200;

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


int getPriority(char check_ch)
{
	switch(check_ch)
	{
		case '(':
			return 0; 
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		default:
			return -1;
	}
}

void infixToPostfix(string infix)
{
	Stack<char> my_stack; 
	
	for(char ch : infix)
	{
		if(ch >= 'A' && ch <= 'Z')
		{
			cout << ch; 
		}
		else
		{
			if(ch == '(')
			{
				my_stack.push(ch);
			}
			else if(ch == ')')
			{
				while(true)
				{
					char pop_ch = my_stack.pop();
					if(pop_ch == '(')
						break;
					cout << pop_ch;
				}
			}
			else
			{
				while(!my_stack.isEmpty())
				{
					if(getPriority(ch) > getPriority(my_stack.peek()))
						break;
					
					char pop_elem = my_stack.pop();
					cout << pop_elem;
				}
				my_stack.push(ch);
			}
		}
	}
	
	while(!my_stack.isEmpty())
	{
		char pop_elem = my_stack.pop();
		cout << pop_elem;
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string input_str;
	getline(cin, input_str);
	
	infixToPostfix(input_str);
	
	return 0;

}