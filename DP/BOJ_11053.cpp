#include <iostream>

using namespace std;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_count(0);
	cin >> input_count;
	
	int *input_arr = new int[input_count];
	int *dp = new int[input_count]; 
	
	int max_result(0);
	
	for(int i = 0; i< input_count; i++)
	{
		int x;
		cin >> x;
		
		input_arr[i] = x;
		
		for(int j=i; j>=0; j--)
		{
			if(j == i)
				dp[i] = 1;
			
			if(input_arr[j] < input_arr[i] && dp[j] >= dp[i])
				dp[i] = dp[j] + 1;
			
			if(max_result < dp[i])
					max_result = dp[i];
		}
	}
	
	cout << max_result << endl;
	
	delete[] input_arr;
	delete[] dp;
			
}