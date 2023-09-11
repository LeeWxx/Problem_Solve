#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_INPUT = 8;
int board[MAX_INPUT][MAX_INPUT];
vector<pair<int,int>> empty_idx;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool setNextBoard(int* arr, int N)
{	
	if(!next_permutation(arr, arr+N))
		return false;
	else
	{
		for(int i=0; i<N; i++)
		{
			if(arr[i] == 1)
			{
				int y = empty_idx[i].first;
				int x = empty_idx[i].second;
				board[y][x] = 1;
			}
		}
	}
	
	return true;
}

void bfs(queue<pair<int, int>> que, int& virus_cnt, int N, int M)
{
	while(!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		
		que.pop();
		
		for(int i=0; i<4; i++)
		{
			int next_y = y + dy[i]; 	
			int next_x = x + dx[i];
		
			if(next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
				continue;
			
			if(board[next_y][next_x] != 0)
				continue;
			
			que.push(make_pair(next_y, next_x));
			board[next_y][next_x] = 2;
			virus_cnt++;
		}
	}
}

int solve(int N, int M)
{
	queue<pair<int,int>> que;
	
	int wall_cnt(0);
	int virus_cnt(0);
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(board[i][j] == 1)
				wall_cnt++;
			else if(board[i][j] == 2)
			{
				virus_cnt++;
				que.push(make_pair(i, j));
			}
		}
	}
	
	bfs(que, virus_cnt, N, M);
	
	int ret = (N * M) - (wall_cnt + virus_cnt);
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;
	
	int** backup_board = new int*[N];
	
	for(int i=0; i<N; i++)
		backup_board[i] = new int[M];
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cin >> board[i][j];
			backup_board[i][j] = board[i][j];
			
			if(board[i][j] == 0)
				empty_idx.push_back(make_pair(i, j));
		}
	}
	
	int per_arr_size = empty_idx.size();
	int* per_arr = new int[per_arr_size];
	
	for(int i=0; i<per_arr_size; i++)
	{
		if(i < per_arr_size-3)
			per_arr[i] = 0;
		else
		{
			per_arr[i] = 1;

			int y = empty_idx[i].first;
			int x = empty_idx[i].second;
			board[y][x] = 1;
		}
			
	}
	
	int result = solve(N, M);
	while(true)
	{	
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				board[i][j] = backup_board[i][j];
			}
		}
		
		if(!setNextBoard(per_arr, per_arr_size))
			break;
		
		result = max(solve(N, M), result);
	}

	for(int i=0; i<N; i++)
		delete[] backup_board[i];
	
	delete[] backup_board;
	delete[] per_arr;
	
	cout << result << endl;
	return 0;
}