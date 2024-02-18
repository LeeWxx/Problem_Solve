#include<vector>
#include<string.h>
#include <queue>

using namespace std;

const int MAX_LEN = 100;

int dist[MAX_LEN][MAX_LEN];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};


int bfs(vector<vector<int> > maps)
{
    int N = maps.size();
    int M = maps[0].size();
    
    queue<pair<int,int>> que;
    que.push(make_pair(0, 0));
    dist[0][0] = 1;
    
    while(!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        
        for(int i=0; i<4; i++)
        {
            int next_y = y + dy[i];
            int next_x = x + dx[i];
            
            if(next_y == N-1 && next_x == M-1)
                return dist[y][x] + 1;
            
            if(next_y >= N || next_x >= M || next_y < 0 || next_x < 0)
                continue;
            
            if(maps[next_y][next_x] == 0)
                continue;
            
            if(dist[next_y][next_x] != -1)
                continue;
            
            que.push(make_pair(next_y, next_x));
            dist[next_y][next_x] = dist[y][x] + 1;
        }
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    memset(dist, -1, sizeof(dist));
    int answer = bfs(maps);
    return answer;
}