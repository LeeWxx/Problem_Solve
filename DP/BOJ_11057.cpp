#include <iostream>
#include <climits>

using namespace std;

const int DIVISOR = 10007;

int safeAdd(int num1, int num2) 
{ 
    if (num1 > INT_MAX - num2) 
        return -1; 
    else
        return ((num1 % DIVISOR) + (num2 % DIVISOR)) % DIVISOR; 
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	int **dp = new int*[N+1];
	
	for(int i=1; i<=N; i++)
		dp[i] = new int[10] {0, };
	
	for(int i=0; i<10; i++)
	{
		dp[1][i] = 1;
	}
	
	for(int i=2; i<=N; i++)
	{
		for(int j=0; j<10; j++)
		{
			for(int k=0; k<=j; k++)
			{
				dp[i][j] = safeAdd(dp[i-1][k], dp[i][j]);
			}
		}
	}
	
	int output(0);
	
	for(int i=0; i<10; i++)
		output = safeAdd(output, dp[N][i]);
	
	cout << output << endl;
	
	for(int i=1; i<=N; i++)
		delete dp[i];
	
	delete dp;
}