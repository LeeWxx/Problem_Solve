#include <iostream>
#include <queue>
#include <string> 
#include <cstring>

using namespace std;
const int MAX_INPUT = 1000;
const int MAX_CRASH_CNT = 10;
int map[MAX_INPUT][MAX_INPUT];
int dist[MAX_INPUT][MAX_INPUT][MAX_CRASH_CNT+1];
int xn[4] = {0, 0, -1, 1};
int yn[4] = {1, -1, 0, 0};

void dfs(int x, int y, int M, int N, int K)
{
	queue<pair<int,int>> que;
	int pos = y * M + x;
	int crash_cnt = 0;
	dist[y][x][crash_cnt] = 1;
	que.push(make_pair(pos, crash_cnt));
	while(!que.empty())
	{
		int u_pos = que.front().first;
		int u_x = u_pos % M;
		int u_y = u_pos / M;
		int crash_cnt = que.front().second;
		que.pop();
		for(int j=0; j<4; j++)
		{
			int next_x = u_x + xn[j];
			int next_y = u_y + yn[j];
			int next_crash_cnt = crash_cnt;
			
			if(next_x < 0 || next_x >= M || next_y < 0 || next_y >= N)
				continue;
			
			if(map[next_y][next_x] == 1)
				next_crash_cnt += 1;
			
			if(next_crash_cnt > K)
				continue;
			
			if(dist[next_y][next_x][next_crash_cnt] != 0 && 
			   dist[next_y][next_x][next_crash_cnt] <= dist[u_y][u_x][crash_cnt] + 1)	
				continue;
			
			dist[next_y][next_x][next_crash_cnt] = dist[u_y][u_x][crash_cnt] + 1;
			
			if(next_x == M-1 && next_y == N-1)
			{
				return;
			}
			
			int next_pos = next_y * M + next_x;
			que.push(make_pair(next_pos, next_crash_cnt));
		}	
	}
}					
		
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(dist, 0, sizeof(dist));
	
	int N, M, K;
	cin >> N >> M >> K;
	for(int i=0; i<N; i++)
	{
		string s;
		cin >> s;
		for(int j=0; j<M; j++)
		{
			map[i][j] = s.at(j) - '0';
		}
	}
	
	dfs(0, 0, M, N, K);
	int result = MAX_INPUT * MAX_INPUT + 1;
	
	for(int i=0; i<=K; i++)
	{
		if(dist[N-1][M-1][i] == 0)
			continue;
		
		result = min(result, dist[N-1][M-1][i]);
	}
	
	if(result == MAX_INPUT * MAX_INPUT + 1) 
		result = -1;
	
	cout << result << endl;
}