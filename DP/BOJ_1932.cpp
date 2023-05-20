#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	int** input_arr = new int*[n+1];
	int** dp = new int*[n+1];
	
	for(int i=1; i<=n; i++)
	{
		input_arr[i] = new int[i+1];
		dp[i] = new int[i+1];
	}
		
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
			cin >> input_arr[i][j];
	}
	
	dp[1][1] = input_arr[1][1];
		
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			if(j==1)
				dp[i][j] = dp[i-1][1] + input_arr[i][j];
			else if(j == i)
				dp[i][j] = dp[i-1][i-1] + input_arr[i][j];
			else
				dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + input_arr[i][j];
		}
		
	}
	
	int output(0);
	
	for(int i=1; i<=n; i++)
		output = max(dp[n][i], output);
		
	cout << output << endl;
		
	for(int i=1; i<=n; i++)
	{
		delete[] input_arr[i];
		delete[] dp[i];
	}
		
	delete[] input_arr;
	delete[] dp;	

}