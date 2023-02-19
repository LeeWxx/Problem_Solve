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


double calculate(char op, double a, double b)
{
	switch(op)
	{
		case '+':
			return a + b; 
		case '-':
			return b - a; 
		case '*':
			return a * b; 
		case '/':
			return b / a; 
		default:
			return 0;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	Stack<double> my_stack; 
	
	int input_count;
	string input_str;
	
	cin >> input_count;
	cin.ignore();
	getline(cin, input_str);
	
	int* alphabet_to_number_arr = new int[input_count];
	
	int idx = 0;
	while(input_count--)
	{
		int x;
		cin >> x;
		
		alphabet_to_number_arr[idx++] = x;
	}
	
	
	for(char ch : input_str)
	{
		if(ch >= 'A' && ch <= 'Z')
		{
			int idx = ch - 'A';
			int x  = alphabet_to_number_arr[idx];
			my_stack.push(x);
		}
		else
		{
			double a = my_stack.pop();
			double b = my_stack.pop(); 
			double val = calculate(ch, a, b);
			
			my_stack.push(val);
		}
	}
	
	if(my_stack.size() != 1)
		return 0; 
	
	double ouput_elem = my_stack.pop();
	cout << fixed;
	cout.precision(2);
	cout << ouput_elem << endl;
	
	delete [] alphabet_to_number_arr;

}