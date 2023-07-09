#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_VTXS = 100 * 100;
vector<int> adj[MAX_VTXS];
int distance_arr[MAX_VTXS];
int arr[100][100];

void dfs(int v, int dist)
{
	distance_arr[v] = dist;
	
	for(int i=0; i<adj[v].size(); i++)
	{
		int next = adj[v][i];
		if(distance_arr[next] == 0 || distance_arr[next] > dist+1)
			dfs(next, dist+1);
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,M;
	cin >> N >> M;
		
		
	for (int i = 0; i < N; i++) 
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = s.at(j) - '0';
        }
	}
		
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(i < N-1)
			{
				if(arr[i][j] == 1 && arr[i+1][j]==1)
				{
					int u = i*M + j;
					int v = (i+1)*M + j;
					
					adj[u].push_back(v);
					adj[v].push_back(u);
				}
			}
			
			if(j < M-1)
			{
				if(arr[i][j] == 1 && arr[i][j+1]==1)
				{
					int u = i*M + j;
					int v = i*M + (j+1);
						
					adj[u].push_back(v);
					adj[v].push_back(u);
					}
				}
			}
		}
		
		dfs(0,1);
		cout << distance_arr[(N * M)-1]  << "\n";
}