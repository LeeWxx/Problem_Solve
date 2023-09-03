#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int board_size = 100;
const int start_point = 1;
const int arrival_point = 100;

int board[board_size + 1];
bool checked[board_size + 1];
vector<int> adj[board_size + 1];


int bfs(int v)
{
	queue<int> que;
	
	que.push(v);
	checked[v] = true;
	
	int dist = 1;
	while(!que.empty())
	{
		int size = que.size();
		for(int i=0; i<size; i++)
		{
			int u = que.front();
			que.pop();
			for(int j=0; j<adj[u].size(); j++)
			{
				int v = adj[u][j];
				
				if(checked[v] == true)
					continue;
				
				if(v == arrival_point)
					return dist;
				
				que.push(v);
				checked[v] = true;
			}
		}
		dist++;
	}
	
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int next[board_size+1] = {0, };
	
	int N, M;
	cin >> N >> M;
	
	for(int i=0; i<N+M; i++)
	{
		int u,v;
		cin >> u >> v;
		
		adj[u].push_back(v);
		next[u] = v;
	} 
	
	for(int i=1; i<=board_size; i++)
	{
		if(next[i] != 0)
			continue;
		
		for(int j=1; j<=6; j++)
		{
			if(next[i+j] != 0)
				adj[i].push_back(next[i+j]);
			else
				adj[i].push_back(i+j);
		}
	}
	
	
	cout << bfs(start_point) << endl;
	
}