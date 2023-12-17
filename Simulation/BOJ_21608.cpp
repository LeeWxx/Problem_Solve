#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int MAX_N = 20;
int board[MAX_N][MAX_N] = {0, };
	
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int getSum(int N, int like_person_num[][4])
{
	int sum = 0;
	for(int x=0; x<N; x++)
	{
		for(int y=0; y<N; y++)
		{
			int num = board[y][x];
			int satisfaction = 0;
			int cnt = 0;
			
			for(int k=0; k<4; k++)
			{
				int nx = dx[k] + x;
				int ny = dy[k] + y;
				
				if(nx > N-1 || nx < 0 || ny > N-1 || ny < 0)
					continue;
				
				for(int i=0; i<4; i++)
				{
					if(board[ny][nx]==like_person_num[num][i])
					{
						cnt++;
						break;
					}
				}
			}
			
			if(cnt == 0)
				satisfaction = 0;
			else
				satisfaction = (int)(pow(10, cnt-1));
			
			sum += satisfaction;
		}
	}
	
	return sum;
}

void setSeatNumber(int N, int num, int like_person_num[])
{
	int most_like = 0;
	int most_empty = 0;
	
	pair<int,int> candidate_seat;
	
	for(int x=0; x<N; x++)
	{
		for(int y=0; y<N; y++)
		{
			if(board[y][x] != 0)
				continue;
			
			int like_cnt = 0;
			int empty_cnt = 0;
			
			for(int k=0; k<4; k++)
			{
				int nx = dx[k] + x;
				int ny = dy[k] + y;
				
				if(nx > N-1 || nx < 0 || ny > N-1 || ny < 0)
					continue;
				
				if(board[ny][nx] == 0)
					empty_cnt++;
				
				else
				{
					for(int i=0; i<4; i++)
					{
						if(board[ny][nx]==like_person_num[i])
							like_cnt++;
					}
				}
					
			}
			
			if(like_cnt > most_like)
			{
				candidate_seat = make_pair(x,y);
				most_like = like_cnt;
				most_empty = empty_cnt;
			}
			else if(like_cnt == most_like && empty_cnt >= most_empty)
			{
				candidate_seat = make_pair(x,y);
				most_empty = empty_cnt;
			}
		}
	}
	
	board[candidate_seat.second][candidate_seat.first] = num;
}

int main(int argc, char* argv[]) {
	int N;
	cin >> N;
	
	int like_person_num[N*N+1][4] = {0, };
	
	for(int i=0; i<N*N; i++)
	{
		int number;
		cin >> number;
		
		for(int j=0; j<4; j++)
		{
			cin >> like_person_num[number][j];
		}
		
		setSeatNumber(N, number, like_person_num[number]);
	}
	
	cout << getSum(N, like_person_num) << endl;
	return 0;
}