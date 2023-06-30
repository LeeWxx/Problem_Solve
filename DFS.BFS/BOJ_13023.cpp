#include <iostream>
#include <vector>

using namespace std;

bool a[2000][2000];
vector<int> g[2000];
vector<pair<int, int>> edges;

void solve(int N, int M)
{
	for(int i=0; i<M; i++)
	{
		int u,v;
		cin >> u >> v;
		
		a[u][v] = a[v][u] = true;
		
		g[u].push_back(v);
		g[v].push_back(u);
		
		edges.push_back({u,v});
		edges.push_back({v,u});
	}
	
	M *= 2;
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<M; j++)
		{
			int A = edges[i].first;
			int B = edges[i].second;
			
			int C = edges[j].first;
			int D = edges[j].second;
			
			if(A == C || A == D || B == C || B == D)
				continue;
			
			if(!a[B][C])
				continue;
				
			for(int i=0; i<g[D].size(); i++)
			{
				int E = g[D][i];
				
				if(E != A && E != B && E != C && E != D)
				{
					cout << 1 << endl; 
					return;
				}
					
			}
		}
	}
	
	cout << 0 << endl;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,M;
	cin >> N >> M;
	
	solve(N, M);
}