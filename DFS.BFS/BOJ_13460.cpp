#include <iostream>
#include <vector>

using namespace std;

const int MAX_INPUT = 10;
const int MAX_MOVE_COUNT = 10;

char board[MAX_INPUT][MAX_INPUT];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

pair<int, int> red_pos;
pair<int, int> blue_pos;

vector<int> getDir(int k)
{
	vector<int> dir(MAX_MOVE_COUNT);
	for(int i=0; i<10; i++)
	{
		dir[i] = k % 4;
		k >>= 2;
	}
	
	return dir;
}

bool check(vector<int> dir)
{
	for(int i=0; i<MAX_MOVE_COUNT-1; i++)
	{
		if(dir[i] == dir[i+1])
			return false;
		
		for(int j=0; j<3; j+=2)
		{
			if(dir[i] == j+1 && dir[i+1] == j+1)
				return false;
			if(dir[i] == j+1 && dir[i+1] == j)
				return false;
		}
	}
	
	return true;
}

int move(int& x, int& y, int dx, int dy, int another_x, int another_y)
{
	int next_x = x + dx;
	int next_y = y + dy;
	
	if(board[next_y][next_x] == 'O')
		{
			x = 0;
			y = 0;
			return 1;	
		}
	else if(board[next_y][next_x] == '#')
		return -1;
	else if(next_x == another_x && next_y == another_y)
		return -1;
	
	
	while(true)
	{
		int next_x = x + dx;
		int next_y = y + dy;
	
		if(board[next_y][next_x] == 'O')
		{
			x = 0;
			y = 0;
			return true;	
		}
		else if(board[next_y][next_x] == '#')
			return 0;
		else if(next_x == another_x && next_y == another_y)
			return 0;
	
		x = next_x;
		y = next_y;
	}
	
	return 0;
}

int solve(vector<int> dir)
{
	int red_y = red_pos.first;
	int red_x = red_pos.second;
	
	int blue_y = blue_pos.first;
	int blue_x = blue_pos.second;
	
	for(int i=0; i<MAX_MOVE_COUNT; i++)
	{		
		int red_check;
		int blue_check;
		
		if(dir[i] == 0)
		{
			if(red_x < blue_x)
			{
				red_check = move(red_x, red_y, dx[0], dy[0], blue_x, blue_y);
				blue_check = move(blue_x, blue_y, dx[0], dy[0], red_x, red_y);
			}
			else
			{
				blue_check = move(blue_x, blue_y, dx[0], dy[0], red_x, red_y);
				red_check = move(red_x, red_y, dx[0], dy[0], blue_x, blue_y);
			}
		}
		else if(dir[i] == 1)
		{
			if(red_x > blue_x)
			{
				red_check = move(red_x, red_y, dx[1], dy[1], blue_x, blue_y);
				blue_check = move(blue_x, blue_y, dx[1], dy[1], red_x, red_y);
			}
			else
			{
				blue_check = move(blue_x, blue_y, dx[1], dy[1], red_x, red_y);
				red_check = move(red_x, red_y, dx[1], dy[1], blue_x, blue_y);
			}
		}
		else if(dir[i] == 2)
		{
			if(red_y < blue_y)
			{
				red_check = move(red_x, red_y, dx[2], dy[2], blue_x, blue_y);
				blue_check = move(blue_x, blue_y, dx[2], dy[2], red_x, red_y);
			}
			else
			{
				blue_check = move(blue_x, blue_y, dx[2], dy[2], red_x, red_y);
				red_check = move(red_x, red_y, dx[2], dy[2], blue_x, blue_y);
			}
		}
		else if(dir[i] == 3)
		{
			if(red_y > blue_y)
			{
				red_check = move(red_x, red_y, dx[3], dy[3], blue_x, blue_y);
				blue_check = move(blue_x, blue_y, dx[3], dy[3], red_x, red_y);
			}
			else
			{
				blue_check = move(blue_x, blue_y, dx[3], dy[3], red_x, red_y);
				red_check = move(red_x, red_y, dx[3], dy[3], blue_x, blue_y);
			}
		}

		if(blue_check == -1 && red_check == -1)
			return MAX_MOVE_COUNT + 1;
		
		if(blue_check == 1)
			return MAX_MOVE_COUNT + 1;
		
		
		if(red_check == 1)
			return i+1;
	}
	
	return MAX_MOVE_COUNT + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cin >> board[i][j];
			
			if(board[i][j] == 'R')
				red_pos = make_pair(i,j);
			else if(board[i][j] == 'B')
				blue_pos = make_pair(i,j);
		}
	}
	
	int answer = MAX_MOVE_COUNT + 1;
	for(int i=0; i<(1<< MAX_MOVE_COUNT * 2); i++)
	{
		vector<int> dir(MAX_MOVE_COUNT);
		dir = getDir(i);
		if(!check(dir))
			continue;
		
		answer = min(solve(dir), answer);
	}
	
	if(answer == MAX_MOVE_COUNT + 1)
		answer = -1;
	
	cout << answer << endl;
}