#include <iostream>

using namespace std;

int min(int a, int b)
{
	if(a < b)
		return a;
	else 
		return b;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	int** dp = new int*[N];
	int** input_arr = new int*[N];
	
	for(int i=0; i<N; i++)
	{
		dp[i] = new int[3];
		input_arr[i] = new int[3];
	}
	
	for(int i=0; i<N; i++)
		for(int j=0; j<3; j++)
			cin >> input_arr[i][j];
	
	dp[0][0] = input_arr[0][0];
	dp[0][1] = input_arr[0][1];
	dp[0][2] = input_arr[0][2];
	
	for(int i =1; i<N; i++)
	{
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + input_arr[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + input_arr[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + input_arr[i][2];
	}
	
	int output = min(min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
	
	cout << output << endl;
	
	for(int i=0; i<N; i++)
	{
		delete[] dp[i];
		delete[] input_arr[i];
	}
	
	delete dp;
	delete input_arr;
}