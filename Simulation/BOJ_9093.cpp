#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;



const int MAX_SENTENCE_LENGTH = 1000;
const int MAX_WORD_LENGTH = 20;

class Stack
{
public:
	Stack() {top = -1; }
	bool isEmpty() {return top == -1; }
	bool isFull() {return top == MAX_SENTENCE_LENGTH-1;}
	
	void push(char ch){
		data[++top] = ch;
	}
	
	char pop(){
		return data[top--];
	}
	
private: 
	int top;
	char data[MAX_SENTENCE_LENGTH];
};

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	int input_count;
	Stack my_stack;
	
	cin >> input_count;
	cin.ignore();
	
	for(int i =0; i<input_count; i++)
	{
		char input_str[MAX_SENTENCE_LENGTH];
		
		cin.getline(input_str, MAX_SENTENCE_LENGTH);
		
		for(int j=0; j<strlen(input_str)+1 ; j++)
		{
			if (isspace(input_str[j]) != 0 or input_str[j] == '\0')
			{
				while(!my_stack.isEmpty())
				{
					cout << my_stack.pop(); 
				}
			
				cout << " ";
			}
			
			else
				my_stack.push(input_str[j]);
			
				
		}
		
		cout<<endl;
		
	}
		
	
	return 0;
}