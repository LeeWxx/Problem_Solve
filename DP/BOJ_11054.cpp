#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N; 
	cin >> N;
	
	int** dp = new int*[N+1];
	int* input_arr = new int[N+1];
	
	for(int i=1; i<=N; i++)
	{
		dp[i] = new int[2];
		cin >> input_arr[i];
	}
	
	for(int i=1; i<=N; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = 1;
		
		for(int j=1; j<i; j++)
		{
			if(input_arr[i] > input_arr[j])
				dp[i][0] = max(dp[j][0] + 1, dp[i][0]);
			else if(input_arr[i] < input_arr[j])
				dp[i][1] = max({dp[j][0] + 1, dp[j][1] + 1, dp[i][1]});
		}
	}
	
	int output(0); 
	
	for(int i=1; i<=N; i++)
	{
		for(int j=0; j<2; j++)
			output = max(dp[i][j], output);;
	}
	
	cout << output << endl;
	
	for(int i=1; i<=N; i++)
		delete[] dp[i];
	
	delete[] dp;
	delete[] input_arr;

}