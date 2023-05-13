#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_num;
	cin >> input_num;
	
	int* dp = new int[input_num+1] {0, };
	
	for(int i=1; i<=sqrt(input_num); i++)
	{
		int square_num = pow(i,2);
		dp[square_num] = 1;
	}
	
	for(int i=2; i<= input_num; i++)
	{
		if(dp[i] != 0)
			continue;
		
		dp[i] = INT_MAX;
		for(int j=1; j<= sqrt(i); j++)
		{
			int square_num = pow(j,2);
			int another = i- square_num;
			dp[i] = min(dp[i], dp[square_num] + dp[another]);
		}
	}
	
	cout << dp[input_num] << endl;
	
	delete[] dp;
}