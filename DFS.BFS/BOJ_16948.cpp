#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_BOARD_SIZE = 200;

vector<pair<int, int>> adj[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
bool checked[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

int xn[6] = {-2, -2, 0, 0, 2, 2};
int yn[6] = {-1, 1, -2, 2, -1, 1};

int bfs(int start_x, int start_y, int arrival_x, int arrival_y, int N)
{
	queue<pair<int, int>> que;
	
	que.push(make_pair(start_x, start_y));
	checked[start_y][start_x] = true;
	
	int dist = 1;
	while(!que.empty())
	{
		int size = que.size();
		for(int i=0; i<size; i++)
		{
			int x = que.front().first;
			int y = que.front().second;
			
			que.pop();
			
			for(int j=0; j<6; j++)
			{
				int next_x = x + xn[j];
				int next_y = y + yn[j];
				
				if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= N)
					continue;
				
				if(checked[next_y][next_x] == true)
					continue;
				
				if(next_x == arrival_x && next_y == arrival_y)
					return dist;
				
				que.push(make_pair(next_x, next_y));
				checked[next_y][next_x] = true;
			}
		}
		dist++;
	}
	
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	int start_x, start_y, end_x, end_y;
	cin >> start_x >> start_y >> end_x >> end_y;
	
	cout << bfs(start_x, start_y, end_x, end_y, N) << endl;
}