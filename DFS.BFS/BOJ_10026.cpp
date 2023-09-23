#include <iostream>
#include <queue>
#include <string>

using namespace std;
const int MAX_INPUT = 100;

char board[MAX_INPUT][MAX_INPUT];
bool checked[MAX_INPUT][MAX_INPUT];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int start_y, int start_x, int N)
{
	queue<pair<int, int>> que;
	que.push(make_pair(start_y, start_x));
	checked[start_y][start_x] = true;
	
	char color = board[start_y][start_x];
	
	while(!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		
		que.pop();
		
		for(int i=0; i<4; i++)
		{
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			
			if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= N)
				continue;
			
			if(checked[next_y][next_x])
				continue;
			
			if(board[next_y][next_x] != color)
				continue;
			
			que.push(make_pair(next_y, next_x));
			checked[next_y][next_x] = true;
		}
	}
	
	return;
}

void cwChange(int N)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			checked[i][j] = false;
			
			if(board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N; 
	
	for(int i=0; i<N; i++)
	{
		string s;
		cin >> s;
		for(int j=0; j<N; j++)
		{
			board[i][j] = s.at(j);
		}
	}
	
	int result(0);
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(checked[i][j])
				continue;
			bfs(i, j, N);
			result++;
		}
	}
	
	cout << result << " ";
	
	cwChange(N);
	
	result = 0;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(checked[i][j])
				continue;
			bfs(i, j, N);
			result++;
		}
	}
	
	cout << result << endl;
	
 	return 0;
}