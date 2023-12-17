#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int MAX_BOARD_SIZE = 50;

int A[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int visited[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


bool Bfs(int start_y, int start_x, int N, int L, int R)
{
	queue<pair<int,int>> que;
	queue<pair<int,int>> union_que;
	int union_pop_sum = 0;
	
	que.push(make_pair(start_y,start_x));
	visited[start_y][start_x] = true;
	union_que.push(make_pair(start_y,start_x));
	
	while(!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		
		que.pop();
		union_pop_sum += A[y][x];
		
		for(int i=0; i<4; i++)
		{
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			
			int population_diff;
			
			if(A[next_y][next_x] >= A[y][x])
				population_diff = A[next_y][next_x] - A[y][x];
			else
				population_diff = A[y][x] - A[next_y][next_x];
			
			if(next_y >= N || next_x >= N || next_y < 0 || next_x < 0)
				continue;
			
			if(population_diff < L || population_diff > R)
				continue;
			
			if(visited[next_y][next_x])
				continue;
			
			que.push(make_pair(next_y, next_x));
			visited[next_y][next_x] = true;
			union_que.push(make_pair(next_y,next_x));
		}
	}
	
	if(union_que.size() > 1)
	{
		int population = union_pop_sum / union_que.size();
	
		while(!union_que.empty())
		{
			int y = union_que.front().first;
			int x = union_que.front().second;
			union_que.pop();
		
			A[y][x] = population;
		}
		return true;
	}
	else
		return false;
}


int Solve(int N, int L, int R)
{
	int day = 0;
	bool is_have_union;
		
	while(true)
	{
		memset(visited, false, sizeof(visited));
		is_have_union = false;
		
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(visited[i][j] == false)
				{
					if(Bfs(i, j, N, L, R))
						is_have_union = true;
				}
			}
		}	
		
		if(is_have_union)
			day++;
		else
			break;
	}
	
	return day;
}


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	
	int L, R;
	cin >> L >> R;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> A[i][j];
		}
	}
	
	cout << Solve(N, L, R) << "\n";
}