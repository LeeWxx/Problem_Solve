#include <iostream>
#include <string>

using namespace std;

const int MAX_VTXS = 50 * 50;
int xn[4] = {-1,1,0,0};
int yn[4] = {0,0,-1,1};
bool checked[MAX_VTXS];
int dist[MAX_VTXS];
int arr[50][50];

void reset(int N, int M)
{
	for(int i=0; i<N*M-1; i++)
		checked[i] = false;
}

bool dfs(int v, int cnt, int N, int M)
{
	if(checked[v])
		return (cnt - dist[v]) >= 4;
	
	checked[v] = true;
	dist[v] = cnt;
	
	int x = (v % M);
	int y = (v / M);
	
	for(int i=0; i<4; i++)
	{
		int next_x = x + xn[i];
		int next_y = y + yn[i];

		if(next_y < 0 || next_y >= N || next_x >= M || next_x < 0)
			continue;
		
		if(arr[next_y][next_x] != arr[y][x])
			continue;
		
		int next = next_y * M + next_x;

		if(dfs(next, cnt+1, N, M))
			return true;
	}
	
	return false;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;
	
	for(int i=0; i<N; i++)
	{
		string s;
		cin >> s;
		for(int j=0; j<M; j++)
		{
			arr[i][j] = s.at(j) - 'A';
		}
	}
	
	bool result = false;
	for(int i=0; i<N*M-1; i++)
	{		
		if(dfs(i, 0, N, M))
			result = true;
		
		if(result)
			break;
		
		reset(N, M);
	}
	
	if(result)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
}