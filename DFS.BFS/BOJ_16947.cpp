#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_INPUT = 3000;

vector<int> adj [MAX_INPUT+1];
bool checked [MAX_INPUT+1];
int dist[MAX_INPUT+1];
bool is_cycle [MAX_INPUT+1];


void print(int N)
{
	for (int i=1; i<=N-1; i++)
		cout << dist[i] << " ";

	cout << dist[N] << endl;
}

void check_reset(int N)
{
	for (int i=1; i<=N; i++)
		checked[i] = false;
}

void distance_reset(int N)
{
	for (int i=1; i<=N; i++)
		dist[i] = false;
}

void bfs(int v)
{
	queue<int> que;
	
	que.push(v);
	checked[v] = true;
	
	int temp_dist = 0;
	
	while (!que.empty())
	{
		int size =  que.size();
		for(int i=0; i<size; i++)
		{
			int u = que.front();
			que.pop();	
			
			if(is_cycle[u] == true)
			{
				dist[v] = temp_dist;
				return;
			}
			
			for(int j=0; j<adj[u].size(); j++)
			{
				int next = adj[u][j];
				
				if(!checked[next])
				{
					checked[next] = true;
					que.push(next);
				}
			}
		}
		
		temp_dist++;
	}
}

bool dfs(int v, int cnt)
{
	if(checked[v])
	{
		if(cnt - dist[v] >= 3)	
		{
			if(!is_cycle[v])
				is_cycle[v] = true;	
			
			return true;
		}
		
		return false;
	}
	
	checked [v] = true;
	dist[v] = cnt;

	for (int i=0; i<adj[v].size(); i++)
	{
		if(dfs(adj[v][i], cnt+1))
			is_cycle[v] = true;
	}
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		int u,v;
		cin >> u >> v;
		
		adj[u].push_back(v); 
		adj[v].push_back(u);
	}
	
	for(int i=1; i<=N; i++)
	{
		dfs(i, 0);
		check_reset (N);
	}
	
	distance_reset (N);
	
	for(int i=1; i<=N; i++)
	{
		bfs(i);
		check_reset (N);
	}
	
	print(N);
}