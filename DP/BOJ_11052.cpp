#include <iostream>

using namespace std;

int Max(int a, int b)
{
	if(a < b)
		return b;
	else
		return a;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	int* dp = new int[N+1] {0,};
	int* price_arr = new int[N+1];
	
	for(int i=1; i<=N; i++)
		cin >> price_arr[i];
	
	for(int j=1; j<= N; j++)
	{
		for(int i=1; i<=j; i++)
		{
			dp[j] = Max(dp[j], dp[j-i] + price_arr[i]);
		}
	}
	
	cout << dp[N] << endl;
		
	delete[] dp;
	delete[] price_arr;
	
}