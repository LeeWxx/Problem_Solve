#include <iostream>

using namespace std;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N; 
	cin >> N;
	
	int* dp = new int[N];
	int* input_arr = new int[N]; 
	
	for(int i=0; i<N; i++)
		cin >> input_arr[i];
	
	dp[0] = input_arr[0];
	
	for(int i=0; i<N; i++)
	{
		dp[i] = input_arr[i];
		
		for(int j=0; j<i; j++)
		{
			if(input_arr[i] > input_arr[j])
				dp[i] = max(dp[j]+input_arr[i], dp[i]);
		}
	}
	
	int output = 0; 
	for(int i=0; i<N; i++)
	{
		output = max(output, dp[i]);
	}
	
	cout << output << endl;
	
	delete[] dp;
	delete[] input_arr;
}