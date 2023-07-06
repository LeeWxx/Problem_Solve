#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_VTXS = 50 * 50;
vector<int> adj[MAX_VTXS];
int checked[MAX_VTXS];
int arr[50][50];

void dfs(int v)
{
	checked[v] = true;
	
	for(int i=0; i<adj[v].size(); i++)
	{
		int next = adj[v][i];
		if(checked[next] == false)
			dfs(next);
	}
}

int solve(int w, int h)
{
	int cnt(0);
	
	for(int i=0; i<w*h; i++)
	{
		for(int j=0; j<adj[i].size(); j++)
		{
			int next = adj[i][j];
			
			if(checked[next] == false)
			{
				dfs(next);
				cnt++;
			}
		}
	
		if(arr[i / w][i % w] == 1 && checked[i] == false)
			cnt++;
	}
	
	return cnt;
}


void reset(int w, int h)
{
	for(int i=0; i<w*h; i++)
	{
		checked[i] = false;
		arr[i / w][i % w] = 0;
		adj[i].clear();
	}
}


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while(true)
	{
		int w,h;
		cin >> w >> h;
		
		if(w == 0 & h == 0)
			break;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
            	cin >> arr[i][j];
        	}
		}
		
		for(int i=0; i<h; i++)
		{
			for(int j=0; j<w; j++)
			{
				if(i < h-1)
				{
					if(arr[i][j] == 1 && arr[i+1][j]==1)
					{
						int u = i*w + j;
						int v = (i+1)*w + j;
					
						adj[u].push_back(v);
						adj[v].push_back(u);
					}
				}
			
				if(j < w-1)
				{
					if(arr[i][j] == 1 && arr[i][j+1]==1)
					{
						int u = i*w + j;
						int v = i*w + (j+1);
						
						adj[u].push_back(v);
						adj[v].push_back(u);
					}
				}
				
				if(i < h-1 && j < w-1)
				{
					if(arr[i][j] == 1 && arr[i+1][j+1]==1)
					{
						int u = i*w + j;
						int v = (i+1)*w + (j+1);
						
						adj[u].push_back(v);
						adj[v].push_back(u);
					}
				}
				
				if(i < h-1 && j > 0)
				{
					if(arr[i][j] == 1 && arr[i+1][j-1]==1)
					{
						int u = i*w + j;
						int v = (i+1)*w + (j-1);
						
						adj[u].push_back(v);
						adj[v].push_back(u);
					}
				}
			}
		}
		
		int result = solve(w,h);
		cout << result << "\n";
		
		reset(w, h);
	}
}