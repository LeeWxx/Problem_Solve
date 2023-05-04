#include <iostream>

using namespace std;

const int DIVISOR = 1000000000;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K; 
	
	long long **dp = new long long* [N+1];
	
	for(int i=0; i<=N; i++)
	{
		dp[i] = new long long[K+1];
		dp[i][1] = 1;
	}
	
	for(int i=2; i<=K; i++)
	{
		for(int j=0; j<=N; j++)
		{
			long long sum(0);
			
			for(int y=0; y<=j; y++)
			{
				sum += (dp[y][i-1] % DIVISOR);
			}
			
			dp[j][i] = (sum % DIVISOR);
		}
	}
	
	cout << dp[N][K] << endl;
	
	for(int i=0; i<=N; i++)
	{
		delete[] dp[i];
	}
	
	delete[] dp;
}