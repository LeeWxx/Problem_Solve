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
		dp[i] = new long long[10] {0, };
	
	for(int i=1; i< 10; i++)
	{
		dp[1][i] = 1;
	}
	
	for(int i=2; i<= input_num; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(j == 0)
				dp[i][j] = dp[i-1][1];
			else if(j == 9)
				dp[i][j] = dp[i-1][8];
			else	
				dp[i][j] = ((dp[i-1][j+1] % divisor) + (dp[i-1][j-1] % divisor)) % divisor; 
		}
	}
	
	long long result(0);
	
	for(int i=0; i<10; i++)
		result += (dp[input_num][i] % divisor);
	
	result %= divisor;
	
	cout << result << endl;

	for(int i=0; i<= input_num; i++)
		delete[] dp[i];

	delete[] dp;
}