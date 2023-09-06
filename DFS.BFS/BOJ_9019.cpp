#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_REGISTER_VALUE = 9999;
const char output[4] = {'D', 'S', 'L', 'R'};

vector<int> adj[MAX_REGISTER_VALUE+1];
bool checked[MAX_REGISTER_VALUE+1];
pair<int, int> pre_instr[MAX_REGISTER_VALUE+1];

void reset()
{
	for(int i=0; i<= MAX_REGISTER_VALUE; i++)
	{
		checked[i] = false;
	}
}

int function_D(int num)
{
	num *= 2;
	
	if(num > 9999)
		return num % 10000;
	
	return num;
}

int function_S(int num)
{
	if(num == 0)
		return 9999;
	
	return num-1;
}

int function_L(int num)
{
	if(num < 1000)
		return num * 10;
	else
	{
		int temp = num / 1000;
		num %= 1000;
		return num * 10 + temp; 
	}
	
}

int function_R(int num)
{
	int temp = num % 10;
	num /= 10;
	return num + (temp * 1000);
}

void print(int start, int now)
{
	if(now != start)
	{
		int pre_register_val = pre_instr[now].first;
		print(start, pre_instr[now].first);	
		cout << output[pre_instr[now].second];
	}
}

void dfs(int v, int target)
{
	queue<int> que;
	
	que.push(v);
	checked[v] = true;
	
	while(!que.empty())
	{
		int size = que.size();
		for(int i=0; i<size; i++)
		{
			int u = que.front();
			que.pop();
			
			for(int j=0; j<adj[u].size(); j++)
			{
				int next = adj[u][j];
				
				if(checked[next])
					continue;
				
				que.push(next);
				checked[next] = true;
				pre_instr[next] = make_pair(u, j);
				
				if(next == target)
				{
					print(v, target);
					cout << "\n";
					return;
				}
				
			}
		}
	}
}

void makeGraph()
{
	for(int i=0; i<=MAX_REGISTER_VALUE; i++)
	{
		adj[i].push_back(function_D(i));
		adj[i].push_back(function_S(i));
		adj[i].push_back(function_L(i));
		adj[i].push_back(function_R(i));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	makeGraph();
	
	int T;
	cin >> T;	
	for(int i=0; i<T; i++)
	{
		int A,B;
		cin >> A >> B;
		dfs(A, B);
		reset();
	}
}