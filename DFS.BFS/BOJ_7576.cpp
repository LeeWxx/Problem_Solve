#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_VTXS = 1000;
vector<int> adj[MAX_VTXS*MAX_VTXS];
int checked[MAX_VTXS*MAX_VTXS];
int arr[MAX_VTXS][MAX_VTXS];


bool check(int N, int M)
{
	for(int i=0; i<M; i++)
	{
		for (int j=0; j<N; j++)
		{			
			if(checked[i*N + j] == false && arr[i][j] != -1)
				return false;
		}
	}
	
	return true;
}

void reset(int N, int M)
{
	for(int i=0; i<M; i++)
	{
		for (int j=0; j<N; j++)
		{
			checked[i*N + j] = false;
		}
	}
}

void bfs(queue<int>* que)
{	
	int size = que->size();
	
	for(int i=0; i<size; i++)
	{
		int u = que->front();
		que->pop();
		
		for(int i=0; i<adj[u].size(); i++)
		{
			int next = adj[u][i];
			
			if(!checked[next])
			{
				que->push(next);
				checked[next] = true;
			}
		}
	}
}

void solve(int N, int M) 
{
	queue<int> que;
	int day = 0;
	
	for(int i=0; i<M; i++)
	{
		for (int j=0; j<N; j++)
		{
			if(arr[i][j])
			{
				que.push(i * N + j);
				checked[i * N + j] = true;
			}
		}
	}
	
	while(!que.empty())
	{
		bfs(&que);
		day++;
	}
	
	bool result = check(N, M);
	
	if(result)
		cout << day-1 << endl;
	else
		cout << -1 << endl;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,M;
	cin >> N >> M;
			
	for(int i=0; i<M; i++)
	{
		for (int j=0; j<N; j++)
			cin >> arr[i][j];
	}
	
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(i < M-1)
			{
				if(arr[i][j] != -1 && arr[i+1][j]!=-1)
				{
					int u = i*N + j;
					int v = (i+1)*N + j;
					
					adj[u].push_back(v);
					adj[v].push_back(u);
				}
				
			}
			
			if(j < N-1)
			{
				if(arr[i][j] != -1 && arr[i][j+1] != -1)
				{
					int u = i*N + j;
					int v = i*N + (j+1);
						
					adj[u].push_back(v);
					adj[v].push_back(u);
				}
				
			}
		}
	}
	
	solve(N,M); 
}