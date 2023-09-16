#include <iostream>
#include <queue>

using namespace std;

const int BOARD_SIZE = 8;

const int START_X = 0;
const int START_Y = BOARD_SIZE-1;

const int END_X = BOARD_SIZE-1;
const int END_Y = 0;

char board[BOARD_SIZE+1][BOARD_SIZE][BOARD_SIZE];
bool checked[BOARD_SIZE+1][BOARD_SIZE][BOARD_SIZE];

int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

void setBoard()
{
	for(int i=0; i<BOARD_SIZE; i++)
	{
		for(int j=0; j<BOARD_SIZE; j++)
		{
			cin >> board[0][i][j];
		}
	}
	
	for(int t=1; t<BOARD_SIZE+1; t++)
	{
		for(int i=0; i<BOARD_SIZE; i++)
		{	
			for(int j=0; j<BOARD_SIZE; j++)
			{
				if(i != 0 && board[t-1][i-1][j] == '#')
					board[t][i][j] = '#';
				else
					board[t][i][j] = '.';
			}
		}
	}
}

void bfs()
{
	queue<pair<int,int>> que;
	
	int second  = 0;
	checked[second][START_Y][START_X] = true;
	
	int pos = START_Y * BOARD_SIZE + START_X;
	que.push(make_pair(second, pos));

	while(!que.empty())
	{
		int second = que.front().first;
		int pos = que.front().second;
		
		que.pop();
		
		int y = pos / BOARD_SIZE;
		int x = pos % BOARD_SIZE;
		
		for(int i=0; i<8; i++)
		{
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			int next_second = second + 1;
			
			if(next_second > BOARD_SIZE)
				next_second = BOARD_SIZE;
			
			if(next_x < 0 || next_y < 0 || next_x >= BOARD_SIZE || next_y >= BOARD_SIZE)
				continue;
			
			if(checked[next_second][next_y][next_x])
				continue;
			
			if(board[second][next_y][next_x] == '#' || board[next_second][next_y][next_x] == '#')
			{
				if(board[next_second][y][x] == '#')
					continue;
					
				next_y = y;
				next_x = x;
			}
			
			int pos = next_y * BOARD_SIZE + next_x;
			que.push(make_pair(next_second, pos));
			
			if(next_y == END_Y && next_x == END_X)
			{
				cout << 1 << endl;
				return;
			}
		}
	}
	
	cout << 0 << endl;
	return;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	setBoard();
	bfs();
	
 	return 0;
}