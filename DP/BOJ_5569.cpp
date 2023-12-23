#include <iostream>
#include <string.h>

using namespace std;

const int MAX_LENGTH = 100;
const int DIVIDEND = 100000;

int dp[MAX_LENGTH][MAX_LENGTH][4];

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(dp, 0, sizeof(dp));
	
	int w, h;
	cin >> w >> h;
	
	dp[0][1][3] = 1;
	dp[1][0][2] = 1;


	for(int i=2; i<h; i++)
	{
		dp[i][0][2] = 1;
	}
	
	for(int j=2; j<w; j++)
	{
		dp[0][j][3] = 1;
	}
	
	for(int i=1; i<h; i++)
	{
		for(int j=1; j<w; j++)
		{
			
			int sum = 0;
			
			dp[i][j][0] = dp[i-1][j][3];
			dp[i][j][1] = dp[i][j-1][2];
			dp[i][j][2] = ((dp[i-1][j][0] % DIVIDEND) + (dp[i-1][j][2] % DIVIDEND)) % DIVIDEND;
			dp[i][j][3] = ((dp[i][j-1][1] % DIVIDEND) + (dp[i][j-1][3]) % DIVIDEND) % DIVIDEND;
		}
	}
	
	int ans = 0;
	
	for(int i=0; i<4; i++)
	{
		ans += dp[h-1][w-1][i];
		ans %= DIVIDEND;
	}

	cout << ans << "\n";
}