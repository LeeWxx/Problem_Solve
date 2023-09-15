#include <iostream>
#include <queue>
#include <string> 
#include <cstring>

using namespace std;
const int MAX_INPUT = 1000;
const int MAX_CRASH_CNT = 10;
int map[MAX_INPUT][MAX_INPUT];
int dist[2][MAX_INPUT][MAX_INPUT][MAX_CRASH_CNT+1];
int xn[4] = {0, 0, -1, 1};
int yn[4] = {1, -1, 0, 0};

void bfs(int x, int y, int M, int N, int K)
{
	queue<pair<int,int>> que;
	int pos = y * M + x;
	int crash_cnt = 0;
	bool is_night = false;
	dist[is_night][y][x][crash_cnt] = 1;
	que.push(make_pair(pos, crash_cnt));
	while(!que.empty())
	{
		int size = que.size();
		
		for(int i=0; i<size; i++)
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
				bool next_is_night = !(is_night);
				
				if(next_x < 0 || next_x >= M || next_y < 0 || next_y >= N)
					continue;
				
				if(map[next_y][next_x] == 1)
				{
					if(is_night == false)
						next_crash_cnt += 1;
					else
					{
						next_x = u_x;
						next_y = u_y;
					}
						
				}
				
				if(next_crash_cnt > K)
					continue;
				
				if(dist[next_is_night][next_y][next_x][next_crash_cnt] != 0)
					continue;
				
				dist[next_is_night][next_y][next_x][next_crash_cnt] = dist[is_night][u_y][u_x][crash_cnt] + 1;
				
				if(next_x == M-1 && next_y == N-1)
				{
					return;
				}
				
				int next_pos = next_y * M + next_x;
				que.push(make_pair(next_pos, next_crash_cnt));
			}	
		}
		is_night = !(is_night);
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
	
	bfs(0, 0, M, N, K);
	
	int result = MAX_INPUT * MAX_INPUT + 11;
	
	for(int i=0; i<=K; i++)
	{
		for(int j=0; j<2; j++)
		{
			if(dist[j][N-1][M-1][i] == 0)
				continue;
			result = min(result, dist[j][N-1][M-1][i]);
		}
	}
	
	if(result == MAX_INPUT * MAX_INPUT + 11) 
		result = -1;
	
	cout << result << endl;
 
    return 0;
}