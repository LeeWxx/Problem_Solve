#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_VTXS = 300 * 300;
vector<int> d_adj[MAX_VTXS];
vector<int> p_adj[MAX_VTXS];
int checked[MAX_VTXS];


bool check(int target_X, int target_Y, int l)
{
	if(checked[(target_X * l) + target_Y])
		return true;
	else
		return false;
}

void reset(int l)
{
	for(int i=0; i<l; i++)
	{
		for (int j=0; j<l; j++)
		{
			checked[i*l + j] = false;
			p_adj[i*l + j].clear();
			d_adj[i*l + j].clear();
		}
	}
}

void bfs(queue<int>* que, int l)
{	
	int size = que->size();
	
	for(int i=0; i<size; i++)
	{
		int u = que->front();
		que->pop();
		
		for(int i=0; i<p_adj[u].size(); i++)
		{
			int next = p_adj[u][i];
			
			for(int j=0; j<d_adj[next].size(); j++)
			{
				int target = d_adj[next][j];

				if(u / l == target / l || u % l == target % l)
					continue;
				
				if(!checked[target])
				{
					que->push(target);
					checked[target] = true;
				}	
			}
		}
	}
}

void solve(int v, int l, int target_x, int target_y) 
{
	queue<int> que;
	int count = 1;
	
	que.push(v);
	checked[v] = true;
	while(!que.empty())
	{
		bfs(&que, l);
		count++;
		
		bool result = check(target_x, target_y, l);
	
		if(result)
		{
			cout << count-1 << endl;
			return;
		}
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int K;
	cin >> K;
	
	while(K--)
	{		
		int l, start_X, start_Y, target_X, target_Y;
		cin >> l;
		cin >> start_X >> start_Y;
		cin >> target_X >> target_Y;
		
		reset(l);
		
		if(start_X == target_X && start_Y == target_Y)
		{
			cout << 0 << "\n";
			continue;
		}
		
		for(int i=0; i<l; i++)
		{
			for(int j=0; j<l; j++)
			{
				if(i < l-1)
				{
					int u = i*l + j;
					int v = (i+1)*l + j;
				
					p_adj[u].push_back(v);
					p_adj[v].push_back(u);
					
				}
			
				if(j < l-1)
				{
					int u = i*l + j;
					int v = i*l + (j+1);
						
					p_adj[u].push_back(v);
					p_adj[v].push_back(u);
				}
				
				if(i < l-1 && j < l-1)
				{
					int u = i*l + j;
					int v = (i+1)*l + (j+1);
						
					d_adj[u].push_back(v);
					d_adj[v].push_back(u);
				}
				
				if(i < l-1 && j > 0)
				{
					int u = i*l + j;
					int v = (i+1)*l + (j-1);
						
					d_adj[u].push_back(v);
					d_adj[v].push_back(u);
				}
			}
		}

		int start = start_X * l + start_Y;
		solve(start, l, target_X, target_Y); 
	}

}