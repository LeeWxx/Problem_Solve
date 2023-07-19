#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_INPUT = 100000;

vector<int> adj[MAX_INPUT+1];
bool checked[MAX_INPUT+1];
int order[MAX_INPUT+1];

bool compare(const int &a, const int &b)
{
	return order[a] < order[b];
}

bool bfs(int v)
{
	queue<int> que;
	int cnt = 0;
	
	if(order[v] != cnt++)
		return false;
	
	que.push(v);
	checked[v] = true;
	
	while(!que.empty())
	{
		int u = que.front();
		que.pop();
		
		for(int i=0; i<adj[u].size(); i++)
		{
			int next = adj[u][i];
			
			if(checked[next])
				continue;
			
			if(order[next] != cnt++)
				return false;
			
			que.push(next);
			checked[next] = true;
		}
	}
	
	return true;
}

int main(int argc, char* argv[]) 
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
	
	for(int i=0; i<N; i++)
	{
		int idx;
		cin >> idx;
		
		order[idx] = i;
	}
		
	
	for(int i=1; i<=N; i++)
	{
		sort(adj[i].begin(), adj[i].end(), compare);
	}
	
	
	if(bfs(1))
		cout << 1 << endl;
	else
		cout << 0 << endl;
	
	return 0;
}