#include <iostream>
#include <queue>
#include <climits>

using namespace std;

const int MAX_INPUT_VALUE = 100;

int input_arr[MAX_INPUT_VALUE][MAX_INPUT_VALUE];
int island_num_arr[MAX_INPUT_VALUE][MAX_INPUT_VALUE]; 
bool checked[MAX_INPUT_VALUE][MAX_INPUT_VALUE];

int xn[4] = {1,-1,0,0};
int yn[4] = {0,0,1,-1};

void reset(int N)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			checked[i][j] = false;

		}
	}
}
			 
int bfs(int N, int x, int y)
{
	queue<pair<int,int>> que;
	que.push(make_pair(x,y));
	
	checked[y][x] = true;
	int island_num = island_num_arr[y][x];
	
	int dist = 0;
	while(!que.empty())
	{
		int size = que.size();
		dist++;
		for(int i=0; i<size; i++)
		{
			int _x = que.front().first;
			int _y = que.front().second;
			
			que.pop();
			
			for(int j=0; j<4; j++)
			{
				int next_x = _x + xn[j];
				int next_y = _y + yn[j];
				
				if(next_x >= N || next_x < 0 || next_y >= N || next_y < 0 )
					continue;

				if(checked[next_y][next_x] == false)
				{
					if(input_arr[next_y][next_x] != 0 && island_num_arr[next_y][next_x] != island_num)
						return dist;
					
					
					que.push(make_pair(next_x, next_y));
					checked[next_y][next_x] = true;
				}
			}
		}
	}
	return INT_MAX;
}
			 
			 
void dfs(int N, int x, int y, int island_num)
{
	island_num_arr[y][x] = island_num;

	for(int i=0; i<4; i++)
	{
		int next_x = x + xn[i];
		int next_y = y + yn[i];
		
		if(next_x >= N || next_x < 0 || next_y >= N || next_y < 0) 
			continue;

		if(input_arr[next_y][next_x] != 1)
			continue;
	
		if(island_num_arr[next_y][next_x] == 0)
			dfs(N, next_x, next_y, island_num);
	}
}

void solve(int N)
{
	int island_num = 1;

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(input_arr[i][j] != 0 && island_num_arr[i][j] == 0)
				dfs(N, j, i, island_num++);	
		}
		
	}
	
	int dist = INT_MAX;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(island_num_arr[i][j] != 0)
			{
				int temp_dist = bfs(N, j, i);
				if(dist > temp_dist)
					dist = temp_dist;
			}
			
			reset(N);
		}
	}
	
	cout << dist-1 << endl;

}


void input(int N)
{
	for(int i=0; i<N; i++)
	{		 
		for(int j=0; j<N; j++)
		{
			cin >> input_arr[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	input(N);
	solve(N);	

}
