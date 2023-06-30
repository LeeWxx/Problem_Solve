#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_VTXS = 1500;

vector<int> adj[MAX_VTXS];
vector<int> output;
bool checked[MAX_VTXS];


void print()
{
	for(int i=0; i<output.size()-1; i++)
	{
		cout << output[i] << " ";
	}
	
	cout << output[output.size()-1] << endl; 
}

void reset()
{
	for(int i=0; i<MAX_VTXS; i++)
		checked[i] = false;
	
	output.clear();
}

void dfs(int v)
{
	checked[v] = true;
	output.push_back(v);
	
	for(int i=0; i<adj[v].size(); i++)
	{
		int next = adj[v][i];
		if(!checked[next])
			dfs(next);
	}
}

void bfs(int v)
{
	queue<int> que;
	que.push(v);
	
	checked[v] = true;
	output.push_back(v);
	while(!que.empty())
	{
		int target = que.front();
		que.pop();
		for(int i=0; i<adj[target].size(); i++)
		{
			int next = adj[target][i];
			if(!checked[next])
			{
				que.push(next);
				checked[next] = true;
				output.push_back(next);
			}
		}
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,M,V;
	cin >> N >> M >> V;
	
	for(int i=0; i<M; i++)
	{
		int u, v;
		cin >> u >> v;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int size = (sizeof(adj)/sizeof(*adj));
	
	for(int i=0; i<size; i++)
		sort(adj[i].begin(), adj[i].end());

	dfs(V);
	print();

	reset();
	
	bfs(V);
	print();
}