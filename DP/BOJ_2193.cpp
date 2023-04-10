#include <iostream>

using namespace std;

const int divisor = 1000000000;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_num;
	cin >> input_num;
	
	long long** dp = new long long*[input_num+1];
	
	for(int i=0; i<= input_num; i++)
		dp[i] = new long long[2];
	
	dp[1][0] = 0;
	dp[1][1] = 1;
	
	for(int i=2; i<= input_num; i++)
	{
		dp[i][1] = dp[i-1][0];
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
	}
	
	long long result(0);
	
	for(int i=0; i<2; i++)
		result += dp[input_num][i];
	
	cout << result << endl;

	for(int i=0; i<= input_num; i++)
		delete[] dp[i];

	delete[] dp;
}