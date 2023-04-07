#include <iostream>

using namespace std;

const int MAX_INPUT_NUM = 100000;
const int divisor = 1000000009;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_count;
	cin >> input_count;
	
	long long dp[MAX_INPUT_NUM+1][4];
	
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	
	for(int i=4; i<= MAX_INPUT_NUM; i++)
	{
		dp[i][3] = ((dp[i-3][1] % divisor) + (dp[i-3][2] % divisor)) % divisor;
		dp[i][2] = ((dp[i-2][1] % divisor) + (dp[i-2][3] % divisor)) % divisor;
		dp[i][1] = ((dp[i-1][2] % divisor) + (dp[i-1][3] % divisor)) % divisor;
	}
	
	while(input_count--)
	{
		int input_num;
		cin >> input_num;
		
		long long result(0);
		
		for(int i=1; i<=3; i++)
			result += (dp[input_num][i] % divisor);
		
		result %= divisor;
		
		cout << result << "\n";
	}	
}