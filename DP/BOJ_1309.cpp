#include <iostream>
#include <climits>

using namespace std;

const int DIVISOR = 9901;

int safeAdd(int num1, int num2) 
{ 
    if (num1 > INT_MAX - num2) 
        return -1; 
    else
        return ((num1 % DIVISOR) + (num2 % DIVISOR)) % DIVISOR; 
}

int safeAddWithThree(int num1, int num2, int num3) 
{ 
    if (num1 > INT_MAX - num2 - num3) 
        return -1; 
    else
        return ((num1 % DIVISOR) + (num2 % DIVISOR) + (num3 % DIVISOR)) % DIVISOR;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	int **dp = new int*[N+1];
	
	for(int i=1; i<=N; i++)
		dp[i] = new int[3];
	
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	
	for(int i=2; i<=N; i++)
	{
		dp[i][0] = safeAddWithThree(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
		
		dp[i][1] = safeAdd(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = safeAdd(dp[i-1][0], dp[i-1][1]);
	}
	
	int output = safeAddWithThree(dp[N][0],dp[N][1],dp[N][2]);
	
	cout << output << endl;
	
	for(int i=1; i<=N; i++)
		delete dp[i];
	
	delete dp;
}