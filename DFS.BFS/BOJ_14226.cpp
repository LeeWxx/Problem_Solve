#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX_POS = 1400;
vector<int> adj[MAX_POS+1];
int second_arr[MAX_POS+1][MAX_POS];

int dfs(int v, int target)
{
	queue<pair<int, int>> que;
	que.push(make_pair(v, 0));

	second_arr[v][0] = 0;

	int sec;
	while(!que.empty())
	{
		int size = que.size();

		for(int i=0; i<size; i++)
		{
			int u = que.front().first;
			int clip = que.front().second;
			
			que.pop();
			
			for(int i=0; i<adj[u].size()+1; i++)
			{
				int next_clip = clip;
				int next_second;
				int next_count;
				if(i != adj[u].size())
				{	
					next_count = adj[u][i];
					
					if(u*2 == next_count)
					{
						next_second = second_arr[u][clip] + 2;
						next_clip = u;
					}
						
					else
						next_second = second_arr[u][clip] + 1;
					
				}
				else if(clip != 0)
				{
					next_count = u + clip; 
					next_second = second_arr[u][clip] + 1;
				}
				
				if(next_count > MAX_POS || next_second >= MAX_POS)
					continue;
				
				if(second_arr[next_count][next_clip] > next_second)
				{
					que.push(make_pair(next_count, next_clip));
					second_arr[next_count][next_clip] = next_second;
				}
			}	
		}
	}
	
	int min_value = INT_MAX;
	for(int i=0; i<target; i++)
	{
		if(second_arr[target][i] != 0)
			min_value = min(min_value, second_arr[target][i]);
	}
	return min_value;	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int K;
	cin >> K;

	adj[MAX_POS].push_back(MAX_POS-1);

	for(int i=1; i<MAX_POS; i++)
	{
		if(i <= MAX_POS/2)
			adj[i].push_back(i*2);

		adj[i].push_back(i-1);
	}
	
	for(int i=0; i<=MAX_POS; i++)
	{
		for(int j=0; j<i; j++)
		{
			second_arr[i][j] = INT_MAX;
		}
	}

	int result = dfs(1,K);
	cout << result << endl;
	
	return 0;
}