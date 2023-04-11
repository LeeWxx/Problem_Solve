#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 1100;
template <typename T> 
class Stack
{
public:
	Stack() {top = -1; }
	bool isEmpty() {return top == -1; }
	void push(T param){
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

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_count(0);
	cin >> input_count;
	
	int *input_arr = new int[input_count];
	int **dp = new int*[input_count]; 
	
	for(int i=0; i<input_count; i++)
		dp[i] = new int[2];
	
	int max_result_index;
	int max_result(0);
	
	for(int i = 0; i< input_count; i++)
	{
		int x;
		cin >> x;
		
		input_arr[i] = x;
		
		for(int j=i; j>=0; j--)
		{
			if(j == i)
			{
				dp[i][0] = 1;
				dp[i][1] = i;
			}
			
			if(input_arr[j] < input_arr[i] && dp[j][0] >= dp[i][0])
			{
				dp[i][0] = dp[j][0] + 1;	
				dp[i][1] = j;
			}
			
			if(max_result < dp[i][0])
			{
				max_result_index = i;
				max_result =dp[i][0];
			}
		}
	}
	
	cout << dp[max_result_index][0] << endl;
	Stack<int> my_stack;
	
	int idx = max_result_index;
	
	while(true)
	{ 
		my_stack.push(input_arr[idx]);
		
		int pre_idx = dp[idx][1];
			
		if(pre_idx == idx)
			break;
		
		idx = pre_idx;
	}
	
	while(!my_stack.isEmpty())
	{
		if(my_stack.size() == 1)
			cout << my_stack.pop(); 
		else 
			cout << my_stack.pop() << " ";
	}
	
	cout << endl;
	
	delete[] input_arr;
	for(int i=0; i<input_count; i++)
		delete[] dp[i];
	delete[] dp;
}