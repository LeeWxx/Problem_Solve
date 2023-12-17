#include <iostream>
#include <queue>

using namespace std;

const int kMaxSize = 50;
char map[kMaxSize][kMaxSize];
int dist[kMaxSize][kMaxSize];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void ResetMap(int h, int w)
{
	for(int i=0; i<h; i++)
	{
		for(int j=0; j<w; j++)
			dist[i][j] = -1;
	}
}

int Bfs(int start_y, int start_x, int h, int w)
{
	int max_dist =0;
	
	queue<pair<int,int>> q;
	q.push(make_pair(start_y,start_x));
	dist[start_y][start_x] = 0;

	
	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			
			if(next_y < 0 || next_x < 0 || next_y >= h || next_x >= w)
				continue;
		
			if(map[next_y][next_x] == 'W')
				continue;
		
			if(dist[next_y][next_x] == -1)
			{
				q.push(make_pair(next_y,next_x));
				dist[next_y][next_x] = dist[y][x] + 1;
				max_dist = max(max_dist, dist[next_y][next_x]);
			}
		}
	}
	
	return max_dist;
}

int GetResult(int h, int w)
{
	int result = 0;
	
	for(int i=0; i<h; i++)
	{
		for(int j=0; j<w; j++)
		{
			if(map[i][j] == 'L')
			{
				ResetMap(h, w);
				result = max(result, Bfs(i, j, h, w));
			}
		}
	}
	
	return result;
}


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int h, w;
	cin >> h >> w;
	
	for(int i=0; i<h; i++)
	{
		for(int j=0; j<w; j++)
		{
			cin >> map[i][j];	
		}
	}
	
	cout << GetResult(h, w) << "\n";
}