#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	int* input_arr = new int[n+1];
	int** dp = new int*[n+1];
		
	for(int i=1; i<=n; i++)
	{
		cin >> input_arr[i];
		dp[i] = new int[3];
	}
		
	dp[1][0] = 0;
	dp[1][1] = input_arr[1];
	dp[1][2] = 0;

	for(int i=2; i<=n; i++)
	{
		dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
		dp[i][1] = dp[i-1][0] + input_arr[i];
		dp[i][2] = dp[i-1][1] + input_arr[i];
	}
		
	int output = max({dp[n][0], dp[n][1], dp[n][2]});
		
	cout << output << endl;
		
	for(int i=1; i<=n; i++)
	{
		delete[] dp[i];
	}
		
	delete[] input_arr;
	delete[] dp;	

}