#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int MAX_BOARD_SIZE = 50;

char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int dist[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int water_map [MAX_BOARD_SIZE][MAX_BOARD_SIZE];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void water_bfs(queue<pair<int,int>> water_que, int start_distance, int N, int M)
{
	int dist = start_distance;
	while(!water_que.empty())
	{
		int size = water_que.size();
		dist++;
		
		for(int i=0; i<size; i++)
		{
			int y = water_que.front().first;
			int x = water_que.front().second;
			
			water_que.pop();
			
			for(int j=0; j<4; j++)
			{
				int next_y = y + dy[j];
				int next_x = x + dx[j];
				
				if(next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
					continue;
				
				if(water_map[next_y][next_x] != 0)
					continue;
				
				if(board[next_y][next_x] != '.')
					continue;
				
				water_map[next_y][next_x] = dist;
				water_que.push(make_pair(next_y, next_x));
			}
		}
	}
	
}

void bfs(int start_y, int start_x, int start_dist, int N, int M)
{
	queue<pair<int,int>> que;
	dist[start_y][start_x] = start_dist;
	int t_dist = start_dist;
	que.push(make_pair(start_y, start_x));
	
	while(!que.empty())
	{
		t_dist++;
		int size = que.size();
		
		for(int i=0; i<size; i++)
		{
			int y = que.front().first;
			int x = que.front().second;
			
			que.pop();
			
			for(int j=0; j<4; j++)
			{
				int next_y = y + dy[j];
				int next_x = x + dx[j];
			
				if(next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
					continue;
				
				if(dist[next_y][next_x] != 0)
					continue;
				
				if(board[next_y][next_x] == 'D')
				{
					cout << t_dist - 1 << endl;
					return;
				}
				
				if(board[next_y][next_x] != '.')
					continue;
				
				if(water_map[next_y][next_x] != 0 && water_map[next_y][next_x] < t_dist + 1)	
					continue;
			
				
				dist[next_y][next_x] = t_dist;
				que.push(make_pair(next_y, next_x));
			}
		}
	}
	
	cout << "KAKTUS" << endl;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int R, C;
	cin >> R >> C;
	
	queue<pair<int,int>> water_que;
	int start_x;
	int start_y;
	
	for(int i=0; i<R; i++)
	{
		string s;
		cin >> s;
		
		for(int j=0; j<C; j++)
		{
			board[i][j] = s.at(j);	
			
			if(board[i][j] == '*')
			{
				water_map[i][j] = 1;
				water_que.push(make_pair(i,j));
			}
			
			else if(board[i][j] == 'S')
			{
				start_y = i;
				start_x = j;
			}
		}
	}
	
	water_bfs(water_que, 1, R, C);
	bfs(start_y, start_x, 1, R, C);
	
 	return 0;
}