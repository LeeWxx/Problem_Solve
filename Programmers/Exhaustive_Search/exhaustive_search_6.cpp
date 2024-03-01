#include <string>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

const int MAX_N = 100;

vector<int> adj[MAX_N+1];
bool checked[MAX_N+1];

void reset(int n)
{
    for(int i=1; i<=n; i++)
        checked[i] = false;
}

int bfs(int start)
{
    int cnt = 1;
    queue<int> que;
    que.push(start);
    
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            
            if(checked[v])
                continue;
            
            que.push(v);
            checked[v] = true;
            cnt++;
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 105;
    
    for(int i=0; i<wires.size(); i++)
    {
        int u = wires[i][0];
        int v = wires[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0; i<wires.size(); i++)
    {
        reset(n);
        
        int u = wires[i][0];
        int v = wires[i][1];
        
        checked[u] = true;
        checked[v] = true;
        
        int gap = abs(bfs(u) - bfs(v));
        
        answer = min(gap, answer);
    }
    
    
    return answer;
}