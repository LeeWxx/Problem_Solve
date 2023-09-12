#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int MAX_INPUT = 1000;
const int DIVISOR = 10;

int board[MAX_INPUT][MAX_INPUT];
bool checked[MAX_INPUT][MAX_INPUT];
int answer[MAX_INPUT][MAX_INPUT];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int y, int x, int N, int M)
{
	int empty_cell_cnt(1);
	vector<pair<int,int>> wall_vec;
	
	queue<pair<int,int>> que;
	que.push(make_pair(y,x));
	checked[y][x] = true;
	
	while(!que.empty())
	{
		int y = que.front().first; 
		int x = que.front().second;
		que.pop();
		
		for(int i=0; i<4; i++)
		{
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			
			if(next_y < 0 || next_x < 0 || next_x >= M || next_y >= N)
				continue;
			
			if(checked[next_y][next_x])
				continue;
			
			if(board[next_y][next_x] == 0)
			{
				pair<int,int> pos = make_pair(next_y,next_x);
				que.push(pos);
				checked[next_y][next_x] = true;
				empty_cell_cnt++;
			}
			else if(board[next_y][next_x] == 1)
			{
				pair<int,int> pos = make_pair(next_y,next_x);
				wall_vec.push_back(pos);
				checked[next_y][next_x] = true;
			}
		}
	}
	
	for(int i=0; i<wall_vec.size(); i++)
	{
		int y = wall_vec[i].first;
		int x = wall_vec[i].second;
		
		answer[y][x] += (empty_cell_cnt % DIVISOR);
		answer[y][x] %= 10;
		checked[y][x] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M; 
	
	for(int i=0; i<N; i++)	
	{
		string s;
		cin >> s;
		for(int j=0; j<M; j++)
		{
			board[i][j] = s.at(j) - '0';
			
			if(board[i][j] == 1)
				answer[i][j] = 1;
		}
	}
	
	for(int i=0; i<N; i++)	
	{
		for(int j=0; j<M; j++)
		{
			if(board[i][j] == 0 && checked[i][j] == false)
			{
				bfs(i, j, N, M);
			}
		}
	}
	
	for(int i=0; i<N; i++)	
	{
		for(int j=0; j<M; j++)
		{
			cout << answer[i][j];
		}
		cout << "\n";
	}
	
}