#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX_N = 200;

vector<int> adj[MAX_N+1];
bool checked[MAX_N+1];

void dfs(int u)
{  
    checked[u] = true;
    
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        
        if(!checked[v])
            dfs(v);
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    memset(checked, false, sizeof(checked));
    
    for(int i=0; i<computers.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            if(computers[i][j] == 1)
            {
                adj[i+1].push_back(j+1);
                adj[j+1].push_back(i+1);
            }
        }
    }
    
    int network_cnt = 0;
    for(int i=1; i<=computers.size(); i++)
    {
        if(!checked[i])
        {
            network_cnt++;
            dfs(i);
        }
    }
    
    answer = network_cnt;
    
    return answer;
}