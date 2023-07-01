#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_VTXS = 20010;
vector<int> adj[MAX_VTXS];
int color_arr[MAX_VTXS];

void dfs(int v, int c)
{
	color_arr[v] = c;
	
	for(int i=0; i<adj[v].size(); i++)
	{
		int next = adj[v][i];
		if(color_arr[next] == 0)
		{
			dfs(next,3-c);
		}
	}
}

bool check()
{
	for(int i=0; i<MAX_VTXS; i++)
	{
		int u_color = color_arr[i];
		for(int j=0; j<adj[i].size(); j++)
		{
			int v_color = color_arr[adj[i][j]];
			
			if(u_color == v_color)
				return false;
		}
	}
	
	return true;
}


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int K;
	cin >> K;
	
	while(K--)
	{
		int V,E;
		cin >> V >> E;
	
		for(int i=0; i<E; i++)
		{
			int u,v;
			cin >> u >> v;
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		for(int i=1; i<=V; i++)
		{
			if(color_arr[i] == 0)
				dfs(i,i % 2 + 1);
		}
	
		bool result = check();
	
		if(result)
			cout << "YES" << "\n"; 
		else
			cout << "NO" << "\n";
		
		for(int i=1; i<=V; i++)
		{
			adj[i].clear();
		}
		
		memset(color_arr, 0,sizeof(color_arr));
		
	}

}