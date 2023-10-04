#include <iostream>
#include <string>

using namespace std;

const int MAX_INPUT = 50;

int board[MAX_INPUT][MAX_INPUT];
int target[MAX_INPUT][MAX_INPUT];

int dx[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
int dy[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};

void onOff(int y, int x)
{
	for(int i=0; i<9; i++)
	{
		int next_y = y + dy[i];
		int next_x = x + dx[i];
		if(board[next_y][next_x] == 0)
			board[next_y][next_x] = 1;
		else
			 board[next_y][next_x] = 0;
	}
}

void input(int N, int M)
{
	string s1;
	for(int i=0; i<N; i++)
	{
		cin >> s1;
		for(int j=0; j<M; j++)
		{
			board[i][j] = s1.at(j) - '0';
		}
	}
	
	string s2;
	for(int i=0; i<N; i++)
	{
		cin >> s2;
		for(int j=0; j<M; j++)
		{
			target[i][j] = s2.at(j) - '0';
		}
	}
}

bool check(int N, int M)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(board[i][j] != target[i][j])
				return false;
			
		}
	}
	
	return true;
}

int solve(int N, int M)
{
	int cnt(0);
	
	for(int i=0; i<N-2; i++)
	{
		for(int j=0; j<M-2; j++)
		{
			if(board[i][j] != target[i][j])
			{
				onOff(i, j); 	
				cnt++; 
			}
			
		}
	}
	
	if(check(N, M))
		return cnt;
	else 
		return -1;
}



int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;
	
	input(N, M);
	cout << solve(N, M) << endl;
 	return 0;
}