#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_VTXS = 1000;
vector<int> adj[MAX_VTXS+1];
int checked[MAX_VTXS+1];

void dfs(int v)
{
	checked[v] = true;
	
	for(int i=0; i<adj[v].size(); i++)
	{
		int next = adj[v][i];
		if(!checked[next])
			dfs(next);
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,M;
	cin >> N >> M;
			

	for (int j = 0; j < M; j++)
	{
		int u,v;
		cin >> u >> v;
			
		adj[u].push_back(v);
		adj[v].push_back(u);
    }
	
	
	int cnt(0);
	
	for(int i=1; i<=N; i++)
	{
		if(!checked[i])
		{
			if(adj[i].size() > 0 )
				dfs(i);
			
			cnt++;	
		}
	}
	
	cout << cnt << endl;
}