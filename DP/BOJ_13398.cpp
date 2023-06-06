#include <iostream>

using namespace std;

const int MIN_INPUT = -1000;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_count;
	cin >> input_count;
	
	int* input_arr = new int[input_count];
	int* dp = new int[input_count];
	int* reverse_dp = new int[input_count];
	
	for(int i=0; i<input_count; i++)
		cin >> input_arr[i];
	
	dp[0] = input_arr[0];
	for(int i=0; i<input_count; i++)
	{
		dp[i] = max(dp[i-1] + input_arr[i], input_arr[i]);
	}
	
	int output(MIN_INPUT-1);
	for(int i=0; i<input_count; i++)
	{
		output = max(output, dp[i]);
	}
	
	reverse_dp[input_count-1] = input_arr[input_count-1];
	for(int i=input_count-2; i>=0; i--)
	{
		reverse_dp[i] = max(reverse_dp[i+1] + input_arr[i], input_arr[i]);
	}
	
	for(int i=1; i<input_count-1; i++)
	{
		output = max(output, dp[i-1] + reverse_dp[i+1]);
	}
	
	cout << output << endl; 
	
	delete[] input_arr;
	delete[] dp;
	delete[] reverse_dp;
	
	
	
	
}