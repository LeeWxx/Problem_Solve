#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX_INPUT = 20;

int shark_pos_X;
int shark_pos_Y;

int board[MAX_INPUT][MAX_INPUT];
bool checked[MAX_INPUT][MAX_INPUT];

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0 ,1};

void eat(int y, int x)
{
	shark_pos_X = x;
	shark_pos_Y = y;
	board[y][x] = 0;
}

int bfs(int N, int shark_level)
{
	memset(checked, false, sizeof(checked));
	
	queue<pair<int, int>> que;
	que.push(make_pair(shark_pos_Y, shark_pos_X));
	checked[shark_pos_Y][shark_pos_X] = true;
	
	vector<int> eat_fish_vec;
	
	int dist(1);
	while(!que.empty())
	{
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
				
				if(next_x < 0 || next_y < 0 || next_y >= N || next_x >= N)
					continue;
				
				if(checked[next_y][next_x])
					continue;
				
				if(board[next_y][next_x] > shark_level)
					continue;
				
				if(board[next_y][next_x] != 0 && board[next_y][next_x] < shark_level)
					eat_fish_vec.push_back(next_y * N + next_x);
				
				
				checked[next_y][next_x] = true;
				que.push(make_pair(next_y, next_x));
			}
		}
		
		if(eat_fish_vec.size() > 1)
			sort(eat_fish_vec.begin(), eat_fish_vec.end());
		
		if(eat_fish_vec.size() >= 1)
		{
			eat(eat_fish_vec[0] / N , eat_fish_vec[0] % N);
			return dist;
		}
		
		dist++;
	}
	
	return -1;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> board[i][j];
			
			if(board[i][j] == 9)
			{
				shark_pos_Y = i;
				shark_pos_X = j;
				board[i][j] = 0;
			}
		}
	}
	
	int shark_level(2);
	int exp(0);
	int sec(0);
	
	while(true)
	{
		int ret = bfs(N, shark_level);
		
		if(ret == -1)
			break;
		
		sec += ret;
		exp++;
		
		if(shark_level == exp)
		{
			shark_level++;
			exp = 0;
		}
	}
	
	cout << sec << endl;
	
 	return 0;
}