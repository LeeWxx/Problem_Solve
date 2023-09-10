#include <iostream>
#include <vector>

using namespace std;

const int MAX_INPUT = 20;
const int MAX_MOVE_COUNT = 5;

int board[MAX_INPUT][MAX_INPUT];
bool is_merge[MAX_INPUT][MAX_INPUT];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<int> getDir(int k)
{
	vector<int> dir(MAX_MOVE_COUNT);
	for(int i=0; i<MAX_MOVE_COUNT; i++)
	{
		dir[i] = k % 4;
		k >>= 2;
	}
	
	return dir;
}

void move(int dir, int N)
{
	int di;
	int start;
	if(dir == 0 || dir == 2)
	{
		start = 0;
		di = 1;
	}
	else
	{
		start = N-1;
		di = -1;
	}
	
	for(int j=start, k=0; k<N; j+=di, k++)
	{
		for(int i=start, k=0; k<N; i+=di, k++)
		{	
			if(board[i][j] == 0)
			{
				continue;
			}
			
			int x = j;
			int y = i;
			
			int next_x = j + dx[dir];
			int next_y = i + dy[dir];
			
			while(true)
			{			
				if(next_x >= N || next_x < 0 || next_y >= N || next_y < 0)
					break;
			
				if(board[next_y][next_x] == board[y][x])
				{
					if(!is_merge[next_y][next_x] && !is_merge[y][x])
					{
						board[next_y][next_x] *= 2;
						board[y][x] = 0;
						is_merge[next_y][next_x] = true;
					}
				}
				else if(board[next_y][next_x] == 0)
				{
					board[next_y][next_x] = board[y][x];
					board[y][x] = 0;
					
					if(is_merge[y][x])
					{
						is_merge[next_y][next_x] = true;
						is_merge[y][x] = false;
					}
				}
				else
					break;
				
				x = next_x;
				y = next_y;
				next_x += dx[dir];
				next_y += dy[dir];
			}
		}
	}
	
}

int solve(vector<int> dir, int N)
{		
	for(int i=0; i<MAX_MOVE_COUNT; i++)
	{
		for(int i=0; i<N; i++)	
		{
			for(int j=0; j<N; j++)
			{
				is_merge[i][j] = false;
			}
		}
		
		int excute_dir = dir[i];
		move(excute_dir, N);
	}
	
	int ret(0);
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			ret = max(ret, board[i][j]);
		}
	}
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	int** backup_board = new int*[N];
	
	for(int i=0; i<N; i++)	
		backup_board[i] = new int[N];
	
	for(int i=0; i<N; i++)	
	{
		for(int j=0; j<N; j++)
		{
			cin >> board[i][j];
			backup_board[i][j] = board[i][j];
		}
	}
	
	int answer = 0;
	for(int i=0; i<(1<< MAX_MOVE_COUNT * 2); i++)
	{
		for(int i=0; i<N; i++)	
		{
			for(int j=0; j<N; j++)
			{
				board[i][j] = backup_board[i][j];
			}
		}
		
		vector<int> dir(MAX_MOVE_COUNT);
		dir = getDir(i);	
		answer = max(solve(dir, N), answer);
	}
	
	cout << answer << endl;
	
	
	for(int i=0; i<N; i++)	
		delete[] backup_board[i];
	
	delete[] backup_board;
}