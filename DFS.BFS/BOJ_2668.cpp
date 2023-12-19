#include <iostream>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

const int MAX_SIZE = 100;

int adj[MAX_SIZE+1];
bool visited[MAX_SIZE+1];
set<int> ans_set;

void bfs(int start)
{
	memset(visited, false, sizeof(visited));
	set<int> temp_set;
	
	queue<int> que;
	que.push(start);
	temp_set.insert(start);
	visited[start] = true;
	
	while(!que.empty())
	{
		int u = que.front();
		que.pop();
		
		int v = adj[u];
		
		if(v == start)
		{
			for(auto it : temp_set) 
				ans_set.insert(it);
			
			return;
		}
		
		if(visited[v])
			continue;
		
		que.push(v);
		temp_set.insert(v);	
		visited[v] = true;
	}
}

void solve(int N)
{	
	for(int i=1; i<=N; i++)
	{
		bfs(i);
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	
	for(int i=1; i<=N; i++)
	{
		int v;
		cin >> v;
		
		adj[i] = v;
	}
	
	solve(N);
	
	cout << ans_set.size() << "\n";
	for(auto it : ans_set)
	{
		cout << it << "\n";
	}
}