#include <iostream>
#include <queue>
#include <string>
#include <climits>

using namespace std;

const int MAX_INPUT_VAL = 100;
int input_arr[MAX_INPUT_VAL+1][MAX_INPUT_VAL+1];
int wall_count[MAX_INPUT_VAL+1][MAX_INPUT_VAL+1];
int xn[4] = {-1, 0, 1, 0};
int yn[4] = {0, -1, 0, 1};

void dfs(int M, int N)
{
	queue<pair<int,int>> que;
	que.push(make_pair(1,1));
	wall_count[1][1] = 0;
	
	while(!que.empty())
	{
		int _x = que.front().first;
		int _y = que.front().second;
		que.pop();

		int wc = wall_count[_y][_x];
		
		for(int i=0; i<4; i++)
		{
			int next_x = _x + xn[i];
			int next_y = _y + yn[i];
			
			if(next_x > M || next_x < 1 || next_y > N || next_y < 1 )
				continue;
			
			int temp;
			if(input_arr[next_y][next_x] == 1)
				temp = wc + 1;	
			else
				temp = wc;
			
			if(temp < wall_count[next_y][next_x])
			{
				que.push(make_pair(next_x,next_y)); 
				wall_count[next_y][next_x] = temp;
			}
		}
	}
}


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int M, N;
	cin >> M >> N;

	for(int i=1; i<=N; i++)
	{
		string s;
		cin >> s;
		
		for(int j=1; j<=M; j++)
		{
			input_arr[i][j] = s.at(j-1) - '0';	
		}
	}
	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			wall_count[i][j] = INT_MAX;
		}
	}

	dfs(M, N);
	cout << wall_count[N][M] << endl;
}