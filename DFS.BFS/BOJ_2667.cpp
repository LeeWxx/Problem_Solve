#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_VTXS = 25 * 25;
vector<int> adj[MAX_VTXS];
int checked[MAX_VTXS];
vector<int> component_vec;
int arr[25][25];

int dfs(int v, int cnt)
{
	checked[v] = true;
	
	for(int i=0; i<adj[v].size(); i++)
	{
		int next = adj[v][i];
		if(checked[next] == false)
			cnt = dfs(next, cnt+1);
	}
	
	return cnt;
}

void solve(int N)
{
	for(int i=0; i<N*N; i++)
	{
		int component_count = 0;
		
		if(checked[i] == false)
		{
			if(arr[i / N][i % N] == 1)
				component_count = 1;
		}
		
		for(int j=0; j<adj[i].size(); j++)
		{
			int next = adj[i][j];
			
			if(checked[next] == false)
				component_count = dfs(next,1);
		}
		
		if(component_count > 0)
			component_vec.push_back(component_count);
	}
}


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
 
        for (int j = 0; j < N; j++) {
            arr[i][j] = input.at(j) - '0';
        }
    }
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(i < N-1)
			{
				if(arr[i][j] == 1 && arr[i+1][j]==1)
				{
					int u = i*N + j;
					int v = (i+1)*N + j;
					
					adj[u].push_back(v);
					adj[v].push_back(u);
				}
			}
			
			if(j < N-1)
			{
				if(arr[i][j] == 1 && arr[i][j+1]==1)
				{
					int u = i*N + j;
					int v = i*N + (j+1);
					
					adj[u].push_back(v);
					adj[v].push_back(u);
				}
			}
		}
	}
	
	solve(N);
	
	cout << component_vec.size() << "\n";
	
	sort(component_vec.begin(), component_vec.end());
	
	for(int i=0; i<component_vec.size(); i++)
		cout << component_vec[i] << "\n";
}