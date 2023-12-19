#include <iostream>
#include <queue>
#include <string.h>
#include <limits.h> 

using namespace std;

const int MAX_SIZE = 200;
const int K_MAX = 30;
int board[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE * MAX_SIZE][K_MAX+1];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int ly[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int lx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

void bfs(int W, int H, int K)
{
	queue<pair<int, int>> que;
	que.push(make_pair(0, K));
	dist[0][K] = 0;
	
	int end_pos = W * H - 1;
	
	while(!que.empty())
	{
		int y = que.front().first / W;
		int x = que.front().first % W;
		
		int pos = y * W + x;
		
		int k = que.front().second;
		
		que.pop();	
		
		for(int i=0; i<4; i++)
		{
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			int next_pos = next_y * W + next_x;
			
			if(next_x < 0 || next_y < 0 || next_x >= W || next_y >= H)
				continue;
			
			if(board[next_y][next_x] == 1)
				continue;
			
			if(dist[next_pos][k] != -1)
				continue;

			que.push(make_pair(next_pos, k));
			dist[next_pos][k] = dist[pos][k] + 1;
		}
		
		if(k == 0)
			continue;
		
		for(int i=0; i<8; i++)
		{
			int next_y = y + ly[i];
			int next_x = x + lx[i];
			
			int next_pos = next_y * W + next_x;

			if(next_x < 0 || next_y < 0 || next_x >= W || next_y >= H)
				continue;
	
			if(board[next_y][next_x] == 1)
				continue;
			
			if(dist[next_pos][k-1] != -1)
				continue;
		
			que.push(make_pair(next_pos, k-1));
			dist[next_pos][k-1] = dist[pos][k] + 1;
		}
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(dist, -1, sizeof(dist));
	
	int K, W, H;
	cin >> K >> W >> H;
	
	for(int i=0; i<H; i++)
	{
		for(int j=0; j<W; j++)
		{
			cin >> board[i][j];
		}
	}
	
	int result;
	
	if(W == 1 && H == 1)
		result = 0;
	else
	{
		bfs(W, H, K);
		result = INT_MAX;
		
		for(int i=0; i<=K; i++)
		{
			if(dist[W*H-1][i] != -1)
				result = min(result, dist[W*H-1][i]);
		}
	}
	
	if(result == INT_MAX)
		cout << -1 << "\n";
	else
		cout << result << "\n";
}