#include <iostream>

using namespace std;

int max(int a, int b)
{
	if(a > b)
		return a;
	else 
		return b;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_count;
	cin >> input_count;
	
	int *input_arr = new int[input_count+1];
	int *dp = new int[input_count+1]; 
	
	int max_result(-1001);
	
	for(int i=1; i<=input_count; i++)
	{
		cin >> input_arr[i];
		dp[i] = max(input_arr[i], dp[i-1] + input_arr[i]);
		
		if(max_result < dp[i])
			max_result = dp[i];
	}
	
	
	
	delete[] input_arr;
	delete[] dp;
	
	cout << max_result << endl;
}