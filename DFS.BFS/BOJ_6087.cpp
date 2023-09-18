#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_INPUT = 100;
char board[MAX_INPUT][MAX_INPUT];
int m_cnt_map[4][MAX_INPUT][MAX_INPUT];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Point {
    int x;
    int y;
	int pre_dir;
	int m_cnt;
};

int bfs(int start_y, int start_x, int end_y, int end_x, int W, int H)
{
	queue<Point> que;
	
	Point start;
	start.x = start_x;
	start.y = start_y;
	start.pre_dir = -1;
	start.m_cnt = 0;
	
	for(int i=0; i<4; i++)
		m_cnt_map[i][start_y][start_x] = start.m_cnt;
	
	que.push(start);
	
	while(!que.empty())
	{
		int x = que.front().x;
		int y = que.front().y;
		int pre_dir = que.front().pre_dir;
		int m_cnt = que.front().m_cnt;

		que.pop();
		
		for(int i=0; i<4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			
			if(next_y < 0 || next_x < 0 || next_y >= H || next_x >= W)
				continue;
			
			if(board[next_y][next_x] == '*')
				continue;
				
			Point next;
			
			next.x = next_x;
			next.y = next_y;
			next.pre_dir = i;
			
			if(pre_dir == -1)
				next.m_cnt = 0;
			else if(pre_dir != i)
				next.m_cnt = m_cnt + 1;
			else
				next.m_cnt = m_cnt;
			
			if(m_cnt_map[next.pre_dir][next_y][next_x] == -1 || m_cnt_map[next.pre_dir][next_y][next_x] > next.m_cnt)
			{
				m_cnt_map[next.pre_dir][next_y][next_x] = next.m_cnt;
			}
			else if(m_cnt_map[next.pre_dir][next_y][next_x] <= next.m_cnt)
				continue;

			que.push(next);
		}
	}

	int ret = W * H;
	for(int i=0; i<4; i++)
	{
		if(m_cnt_map[i][end_y][end_x] == -1)
			continue;
		
		ret = min(ret, m_cnt_map[i][end_y][end_x]);
	}
	
	return ret;
}
 
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(m_cnt_map, -1, sizeof(m_cnt_map));
	
	int W, H;
	cin >> W >> H;
	
	int start_x(-1);
	int start_y(-1);
	
	int end_x(-1);
	int end_y(-1);
	
	for(int i=0; i<H; i++)
	{
		for(int j=0; j<W; j++)
		{
			cin >> board[i][j];
			
			if(board[i][j] == 'C')
			{
				if(start_y == -1)
				{
					start_y = i;
					start_x = j;
				}	
				else
				{
					end_y = i;
					end_x = j;
				}
			}
		}
	}
	
	cout << bfs(start_y, start_x, end_y, end_x, W, H) << endl;
	
 	return 0;
}