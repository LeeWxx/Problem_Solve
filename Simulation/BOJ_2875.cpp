#include <iostream>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M, K;
	cin >> N >> M >> K;
	
	while(K--)
	{
		if(N/2 >= M)
			N--;
		else
			M--;
	}
	
	int ans = min(N/2, M);
	cout << ans << endl;
}