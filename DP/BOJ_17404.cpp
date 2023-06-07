#include <iostream>

using namespace std;

const int MAX_HOUSE_COUNT = 1000;
const int MAX_EXPENSE = 1000;

int solve(int* input_arr[3], int N, int start_idx)
{
	int** dp = new int*[N+1];
	
	for(int i=1; i<=N; i++)
		dp[i] = new int[3];
		
	for(int i=0; i<3; i++)
	{
		if(i == start_idx)
		{
			dp[2][start_idx] = MAX_EXPENSE * 2 + 1;
			continue;
		}
			
		
		dp[2][i] = input_arr[1][start_idx] + input_arr[2][i];
	}
	
	for(int i=3; i<=N; i++)
	{
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + input_arr[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + input_arr[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + input_arr[i][2];
	}
	
	int ret = MAX_EXPENSE * MAX_HOUSE_COUNT;
	
	for(int i=0; i<3; i++)
	{
		if(i == start_idx)
			continue;
		
		ret = min(ret, dp[N][i]);
	}
	
	for(int i=1; i<=N; i++)
		delete dp[i];
	
	delete dp;
	
	return ret;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	int** input_arr = new int*[N+1];
	
	for(int i=1; i<=N; i++)
		input_arr[i] = new int[3];
	
	for(int i=1; i<=N; i++)
	{
		for(int j=0; j<3; j++)
		{
			cin >> input_arr[i][j];		
		}
	}
	
	int output = MAX_EXPENSE * MAX_HOUSE_COUNT;
	
	for(int i=0; i<3; i++)
		output = min(solve(input_arr, N, i), output);
	
	cout << output << endl;
	
	for(int i=1; i<=N; i++)
		delete input_arr[i];
	
	delete input_arr;
}