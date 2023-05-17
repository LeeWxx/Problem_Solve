#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_count;
	cin >> input_count;
	
	while(input_count--)
	{
		int n;
		cin >> n;
		
		int** input_arr = new int*[n+1];
		int** dp = new int*[n+1];
		
		for(int i=1; i<=n; i++)
		{
			input_arr[i] = new int[2];
			dp[i] = new int[3];
		}
		
		for(int i=0; i<2; i++)
			{
			for(int j=1; j<=n; j++)
			{
				cin >> input_arr[j][i];
			}
		}
		
		dp[1][0] = 0;
		dp[1][1] = input_arr[1][0];
		dp[1][2] = input_arr[1][1];
		
		for(int i=2; i<=n; i++)
		{
			dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
			dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + input_arr[i][0];
			dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + input_arr[i][1];
		}
		
		int output = max({dp[n][0], dp[n][1], dp[n][2]});
		
		cout << output << "\n";
		
		for(int i=1; i<=n; i++)
		{
			delete[] input_arr[i];
			delete[] dp[i];
		}
		
		delete[] input_arr;
		delete[] dp;
	}
}