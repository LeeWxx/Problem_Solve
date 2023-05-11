#include <iostream>

using namespace std;

const int MAX_INPUT = 1000000;
const int DIVISOR = 1000000009;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long dp[MAX_INPUT+1];
	
	dp[1] = 1;
	dp[2] = 2; 
	dp[3] = 4;
	
	for(int i=4; i<= MAX_INPUT; i++)
	{
		dp[i] = ((dp[i-1] % DIVISOR) + (dp[i-2] % DIVISOR) + (dp[i-3] % DIVISOR)) % DIVISOR;;
	}
	
	int input_count;
	cin >> input_count;	
	
	while(input_count--)
	{
		int input_num;
		cin >> input_num;
		
		cout << dp[input_num] << "\n";
	}
}