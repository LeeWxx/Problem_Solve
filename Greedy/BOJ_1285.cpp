#include <iostream>
#include <string>

using namespace std;

const int MAX_INPUT = 20;
char board[MAX_INPUT][MAX_INPUT]; 

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N; 
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		string s;
		cin >> s;
		for(int j=0; j<N; j++)
		{
		 	board[i][j] = s.at(j);
		}
	}
	
	int ans = N * N + 1;
	
	for(int k=0; k<(1<<20); k++)
	{
		int sum(0);
		for(int j=0; j<N; j++)
		{
			int head_cnt(0);
			for(int i=0; i<N; i++)
			{
				bool is_head = false;
				if(board[i][j] == 'H')
					is_head = true;
					
				if((1 << i) & k)
					is_head = !is_head;
				
				if(is_head)
					head_cnt++;
				
			}
			
			if(N - head_cnt > head_cnt)
				sum += head_cnt;
			else
				sum += N - head_cnt;
		}
		
		ans = min(ans, sum);
	}
	
	cout << ans << endl;
	
 	return 0;
}