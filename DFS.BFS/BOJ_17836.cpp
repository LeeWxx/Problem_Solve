#include <iostream>
#include <queue>
#include <string.h>
#include <cstdlib>
#include <limits.h>

using namespace std;

const int MAX_BOARD_SIZE = 100;
int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int dist[MAX_BOARD_SIZE][MAX_BOARD_SIZE];


int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int getDist(int x1, int x2, int y1, int y2)
{
	int dist = 0;
	
	dist += abs(x2 - x1);
	dist += abs(y2 - y1);
	
	return dist;
}

int bfs(int N, int M)
{
	int min_dist = INT_MAX;
	queue<pair<int, int>> que;
	que.push(make_pair(0, 0));
	dist[0][0] = 0;
	
	while(!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();
		
		for(int i=0; i<4; i++)
		{
			int next_y = dy[i] + y;
			int next_x = dx[i] + x;
			
			if(dist[next_y][next_x] != -1 ||
			  next_y >= N || next_x >= M || next_y < 0 || next_x < 0 ||
			  board[next_y][next_x] == 1)
				continue;
			
			if(board[next_y][next_x] == 2)
				min_dist = min(min_dist, (dist[y][x] + 1) + getDist(next_x, M-1, next_y, N-1));
			
			if(next_y == N-1 && next_x == M-1)
				min_dist = min (min_dist, (dist[y][x] + 1));

			que.push(make_pair(next_y, next_x));
			dist[next_y][next_x] = dist[y][x] + 1;
		}
	}
	
	return min_dist;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(dist, -1, sizeof(dist));
	
	int N, M, T;
	cin >> N >> M >> T;
	
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cin >> board[i][j];		
		}
	}
	
	
	int find_time = bfs(N, M);
	
	if(T < find_time)
		cout << "Fail" << "\n";
	else
		cout << find_time << "\n";
}