#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX_POS = 140000;
vector<int> adj[MAX_POS+1];
int second_arr[MAX_POS+1];


int dfs(int v, int target)
{
	queue<int> que;
	que.push(v);

	second_arr[v] = 0;

	int sec;
	while(!que.empty())
	{
		int size = que.size();

		for(int i=0; i<size; i++)
		{
			int u = que.front();
			que.pop();
			
			for(int i=0; i<adj[u].size(); i++)
			{
				int next = adj[u][i];
		
				if(u*2 == next)
					sec = second_arr[u];
				else
					sec = second_arr[u] + 1;
				
				
				if(second_arr[next] > sec)
				{
					que.push(next);
					second_arr[next] = sec;
				}
			}	
		}
	}
	
	return second_arr[target];	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, K;
	cin>> N >> K;
	
	if(N==K)
	{
		cout << 0 << endl;
		return 0;
	}

	adj[MAX_POS].push_back(MAX_POS-1);
	adj[0].push_back(1);

	for(int i=1; i<MAX_POS; i++)
	{
		if(i <= MAX_POS/2)
			adj[i].push_back(i*2);

		adj[i].push_back(i+1); 
		adj[i].push_back(i-1);
	}
	
	for(int i=0; i<=MAX_POS; i++)
		second_arr[i] = INT_MAX;

	int result = dfs(N,K);
	cout << result << endl;
	
	return 0;
}