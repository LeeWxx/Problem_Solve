#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_INPUT_VTXS = 100000;

int dist_arr[MAX_INPUT_VTXS+1];
vector<pair<int,int>> adj[MAX_INPUT_VTXS+1];

void dfs(int v, int dist)
{
	dist_arr[v] = dist;
	
	for(int i=0; i<adj[v].size(); i++)
	{
		int next_vtx = adj[v][i].first;
		int edge_dist = adj[v][i].second;
		
		if(dist_arr[next_vtx] != -1)
			continue;
		
		dfs(next_vtx, dist + edge_dist);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(dist_arr, -1, sizeof(int) * (MAX_INPUT_VTXS+1));
	
	int V;
	cin >> V;
	
	for(int i=0; i<V; i++)
	{
		int vtx;
		cin >> vtx;
		
		while(true)
		{
			int target_vtx;
			cin >> target_vtx;
			
			if(target_vtx == -1)
				break;
			
			int edge_dist;
			cin >> edge_dist;
		
			adj[vtx].push_back(make_pair(target_vtx, edge_dist));
		}
	}
	
	dfs(1, 0);
	
	int max_dist(-1);
	int far_vtx(0);
	for(int i=1; i<=V; i++)
	{
		if(max_dist < dist_arr[i])
		{
			max_dist = max(max_dist, dist_arr[i]);
			far_vtx = i;
		}	
	}
	
	memset(dist_arr, -1, sizeof(int) * (MAX_INPUT_VTXS+1));
	
	dfs(far_vtx, 0);
	
	max_dist = -1;
	for(int i=1; i<=V; i++)
		max_dist = max(max_dist, dist_arr[i]);
	
	
	cout << max_dist << endl;
}