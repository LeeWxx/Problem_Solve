#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_POS = 140000;
vector<int> adj[MAX_POS+1];
bool checked[MAX_POS+1];
int pre_pos[MAX_POS+1];

void go(int v, int cnt)
{
	int u = pre_pos[v];
	
	if(u != -1)
		go(u, cnt+1);
	
	if(cnt==0)
		cout << v << endl;
	else
		cout << v << " ";
}

int dfs(int v, int target)
{
	queue<int> que;
	que.push(v);

	checked[v] = true;
	pre_pos[v] = -1;

	int sec = 0;

	while(!que.empty())
	{
		sec++;

		int size = que.size();

		for(int i=0; i<size; i++)
		{
			int u = que.front();
			que.pop();
			
			for(int i=0; i<adj[u].size(); i++)
			{
				int next = adj[u][i];
		
				if(checked[next] == false)
				{
					pre_pos[next] = u;
					if(next == target)
						return sec;
			
					que.push(next);
					checked[next] = true;
				}
			}	
		}
	}
	
	return sec;	
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
		cout << K << endl;
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

	int result = dfs(N,K);
	cout << result << endl;
	go(K, 0);
	
	return 0;
}