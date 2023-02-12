#include <iostream>
#include <cstring>
#include <string>


using namespace std;

const int MAX_TEXT_COUNT = 600000;
const int SET_TEXT_COUNT = 100000;

template <typename T> 
class Stack
{
public:
	Stack() {top = -1; }
	bool isEmpty() {return top == -1; }
	bool isFull() {return top == MAX_TEXT_COUNT-1;}
		
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
	T data[MAX_TEXT_COUNT+1];
};

	
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_count;	
	cin >> input_count;
	
	string output = "";
	
	Stack<int> my_stack;
	
	bool correct = true;
	
	int push_num = 0;
	while(input_count--)
	{
		int x;
		cin >> x; 
		
		if(x>push_num){
			while(push_num < x){
				my_stack.push(++push_num);
				output += "+";	
			}
			my_stack.pop();
			output += "-";
		}
		else if(x<push_num)
		{
			int elem = -1;
			
			if (!my_stack.isEmpty())
				elem = my_stack.pop();
			
			if(elem != x)
			{
				cout << "NO" << endl;
				correct = false;
				break;	
			}

			output += "-";
		}	
	}
	
	if(correct == true)
	{
		for(char a : output)
		{
			cout << a << '\n';
		}
	}
	
	cout << endl;
	
	return 0;
}