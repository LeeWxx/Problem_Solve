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

class Editor
{
	
public:
	Editor(char text[])
	{
		for(int i = 0; i<strlen(text); i++){
			left_stack.push(text[i]);	
		}
	}
	
	void cursorLeftMove();
	void cursorRightMove();
	void deleteLeftText(); 
	void append(char param);
	void parse(string instr);
	void print();
	
	
private:
	Stack<char> left_stack;
	Stack<char> right_stack;
};

void Editor::cursorLeftMove()
{
	if (left_stack.isEmpty())
		return;
	char tmp = left_stack.pop();
	right_stack.push(tmp);
}

void Editor::cursorRightMove()
{
	if (right_stack.isEmpty())
		return;
	char tmp = right_stack.pop();
	left_stack.push(tmp);
}

void Editor::deleteLeftText()
{
	if (left_stack.isEmpty())
		return;
	left_stack.pop();
}

void Editor::append(char param)
{
	if(left_stack.size() + right_stack.size() > MAX_TEXT_COUNT)
		return;
	left_stack.push(param);
}

void Editor::parse(string instr)
{
	if(instr[0] == 'L')
		cursorLeftMove();
	else if(instr[0] == 'D')
		cursorRightMove();
	else if(instr[0] == 'B')
		deleteLeftText();
	else if(instr[0] == 'P')
		append(instr[2]);
}	

void Editor::print()
{
	int total_size = left_stack.size() + right_stack.size();
	char output_str[total_size];
	output_str[total_size] = '\0';
	int i = left_stack.size();
	
	while(right_stack.size() > 0){
		output_str[i++] = right_stack.pop();
	}
	
	
	while(left_stack.size() > 0){	
		char elem = left_stack.pop();
		output_str[left_stack.size()] = elem;
	}
	
	cout << output_str << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	char text_set[SET_TEXT_COUNT+1];
	cin.getline(text_set, SET_TEXT_COUNT+1);
	Editor editor(text_set);
	
	int input_count;	
	
	cin >> input_count;
	cin.ignore();
	
	while(input_count--)
	{
		string input_str;
		getline(cin, input_str);
		editor.parse(input_str);
	}
	
	editor.print();
		
	return 0;
}