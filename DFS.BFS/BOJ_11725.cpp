#include <iostream>
#include <vector>

using namespace std;

const int MAX_INPUT = 100000; 
vector<int> adj[MAX_INPUT+1]; 
int parent[MAX_INPUT+1];

void print(int N)
{
	for(int i=2; i<N; i++)
		cout << parent[i] << "\n";
	
	cout << parent[N] << endl;
}

void dfs(int from, int u)
{
	if(u != 1)
		parent[u] = from;
	
	for(int i=0; i<adj[u].size(); i++)
	{
		int next = adj[u][i];
		if(parent[next] != 0)
			continue;
		dfs(u, next);	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	for(int i=0; i<N-1; i++)
	{
		int u,v;
		
		cin >> u >> v;	
		
		adj[u].push_back(v); 
		adj[v].push_back(u);
	}

	dfs(0, 1);
	print(N);
}