#include <iostream>

using namespace std;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	long long* dp = new long long[N+1];
	
	dp[0] = 1;
	dp[2] = 3;
	
	for(int i=4; i<=N; i++)
	{
		if(i % 2 != 0)
		{
			dp[i] = 0;
			continue;
		}
		
		dp[i] = (dp[i-2] * 3);
		
		for(int j=4; j<=i; j+=2)
			dp[i] += (dp[i-j] * 2);
	}
	
	cout << dp[N] << endl;
	
	delete[] dp;
}