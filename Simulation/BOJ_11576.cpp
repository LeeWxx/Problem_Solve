#include <iostream>
#include <cmath>

using namespace std;
const int MAX_STACK_SIZE = 1000000;

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
	
private: 
	int top;
	T data[MAX_STACK_SIZE+1];
};

int main(int argc, char* argv[]) 
{
	int base_A, base_B; 
	
	cin >> base_A >> base_B;
	
	int input_count;
	cin >> input_count;
	
	int base_10_num(0);
	
	for(int i=0; i< input_count; i++)
	{
		int x;
		cin >> x;
		base_10_num += x * pow(base_A, input_count-(i+1));
	}
	
	Stack<int> result_stack; 
	
	while(true)
	{
		int quotient = base_10_num / base_B;
		int remainder = base_10_num % base_B; 
		
		result_stack.push(remainder); 
		
		if(base_B > quotient)
		{
			result_stack.push(quotient);
			break;
		}
		
		base_10_num = quotient;
	}
	
	while(!result_stack.isEmpty())
		cout << result_stack.pop() << ' ';
	
	cout << endl;
}