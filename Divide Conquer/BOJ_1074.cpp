#include <iostream>
#include <cmath>

using namespace std;

int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};

	
int solve(int start_y, int start_x, int N, int& cnt, int target_y, int target_x)
{
	int answer(0);
	
	if(N == 2)
	{
		for(int i=0; i<4; i++)
		{
			int y = start_y + dy[i];
			int x = start_x + dx[i];
			
			if(target_y == y && target_x == x)
				return cnt;
			
			cnt++;
		}
		
		return 0;
	}
		
	for(int i=0; i<4; i++)
	{
		int y = start_y + (dy[i] * N / 2);
		int x = start_x + (dx[i] * N / 2);
		
		if(y + N / 2 >= target_y && x + N / 2 >= target_x && y <= target_y && x <= target_x)
		{
			int ret = solve(y, x, N / 2, cnt, target_y, target_x);
		
			if(ret != 0)
				answer = ret;
		}
		else
		{
			cnt += N / 2 * N / 2;
		}
	}
	
	return answer;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, r, c;
	cin >> N >> r >> c;
	
	int cnt(0);
	cout << solve(0, 0, pow(2, N), cnt, r, c) << endl;
	
	return 0;
}
