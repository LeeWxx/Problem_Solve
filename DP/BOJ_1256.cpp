#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;
const int MAX_K = 1000000000;
int dp[MAX_SIZE+1][MAX_SIZE+1];

bool solve(int N, int M, int K, string& ans)
{	
	for(int i=1; i<=N; i++)
		dp[i][0] = 1;
	
	for(int j=1; j<=M; j++)
		dp[0][j] = 1;
		
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			dp[i][j] = min(MAX_K, dp[i-1][j] + dp[i][j-1]);
		}
	}
	
	if(dp[N][M] < K)
		return false;
	
	int a_cnt = N;
	int z_cnt = M;

	while(a_cnt > 0 || z_cnt > 0)
	{
		if(a_cnt == 0)
		{
			ans += 'z';
			z_cnt--;
		}
		else if(z_cnt == 0)
		{
			ans += 'a';
			a_cnt--;
		}
		else if(dp[a_cnt-1][z_cnt] < K)
		{
			ans += 'z';
			K -= dp[a_cnt-1][z_cnt];
			z_cnt--;
		}
		else
		{
			ans += 'a';
			a_cnt--;	
		}
	}
		
	return true;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	int N, M, K;
	cin >> N >> M >> K;
	
	string ans = "";
	
	if(!solve(N, M, K, ans))
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << ans << "\n"; 
	}
}