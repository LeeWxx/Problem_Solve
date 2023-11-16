#include <iostream>
#include <queue>

using namespace std;

const int MAX_INPUT = 100;

char board[MAX_INPUT][MAX_INPUT];
bool checked[MAX_INPUT][MAX_INPUT];

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

struct Data
{
	int x;
	int y;
	int s;
};

int check(int i, int j, int& cnt, int N, int M)
{
	int length(0);
	for(int l = 1; l<=MAX_INPUT; l++)
	{
		bool is_needed = false;
		
		for(int k=0; k<5; k++)
		{
			int col = i + (dy[k] * l);
			int row = j + (dx[k] * l);
			
			if(col < 0 || row < 0 || col >= N ||row >= M)
				return length;
			
			if(board[col][row] != '*')
				return length;
			
			if(!checked[col][row])
				is_needed = true;
		}
		
		if(is_needed)
		{
			for(int k=0; k<5; k++)
			{
				int col = i + (dy[k] * l);
				int row = j + (dx[k] * l);
				
				if(!checked[col][row])
				{
					cnt++;
					checked[col][row] = true;
				}
			}
			
			length = l;
		}
	}
	
	return length;
}

void print(queue<Data>& que)
{
	int size = que.size();
	cout << size << "\n";
	
	for(int i=0; i<size; i++)
	{
		Data data = que.front();
		que.pop();
		
		cout << data.x << " " << data.y << " " << data.s << "\n";
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	int target_count(0);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cin >> board[i][j];
			
			if(board[i][j] == '*')
				target_count++;
		}
	}
	
	
	int cnt(0);
	queue<Data> que;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			int ret = check(i, j, cnt, N, M);
			
			if(ret != 0)
			{
				Data data;
				data.x = i + 1;
				data.y = j + 1;
				data.s = ret;
				
				que.push(data);
			}
			
			if(target_count == cnt)
			{
				print(que);
				return 0;
			}
		}
	}
	
	cout << -1 << endl;
}



