#include <iostream>
#include <cmath>

using namespace std;

struct DTO
{
	int minus_cnt = 0;
	int zero_cnt = 0;
	int plus_cnt = 0;
};

struct Paper
{
    int start_x = 0;
	int start_y = 0;
	int length = 0;
	int num = 0;
};

DTO Check(Paper paper);

const int MAX_INPUT = pow(3,7);
int board[MAX_INPUT][MAX_INPUT];

DTO Split(Paper paper)
{
	int minus_cnt(0);
	int zero_cnt(0);
	int plus_cnt(0);
	
	int limit = paper.length / 3;
	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			Paper new_paper;
			new_paper.start_y = paper.start_y + i * limit;
			new_paper.start_x = paper.start_x + j * limit;
			new_paper.length = limit;
			new_paper.num = board[new_paper.start_y][new_paper.start_x];
			
			DTO ret_dto = Check(new_paper);
			
			minus_cnt += ret_dto.minus_cnt;
			zero_cnt += ret_dto.zero_cnt; 
			plus_cnt += ret_dto.plus_cnt; 
		}
	}
	
	DTO ret_dto;
	ret_dto.minus_cnt = minus_cnt;
	ret_dto.zero_cnt = zero_cnt;
	ret_dto.plus_cnt = plus_cnt;
	
	return ret_dto;
}

DTO Check(Paper paper)
{ 
	for(int i=0; i<paper.length; i++)
	{
		for(int j=0; j<paper.length; j++)
		{
			if(board[paper.start_y + i][paper.start_x + j] != paper.num)
			{
				return Split(paper);
			}
		}
	}
	
	
	DTO ret_dto;
	
	if(board[paper.start_y][paper.start_x] == -1)
		ret_dto.minus_cnt = 1;
	else if(board[paper.start_y][paper.start_x] == 0)
		ret_dto.zero_cnt = 1;
	else if(board[paper.start_y][paper.start_x] == 1)
		ret_dto.plus_cnt = 1;
	
	return ret_dto;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> board[i][j];
		}
	}
	
	Paper paper;
	paper.start_y = 0;
	paper.start_x = 0;
	paper.length = N;
	paper.num = board[0][0];
	
	DTO dto = Check(paper);
	
	cout << dto.minus_cnt << "\n";
	cout << dto.zero_cnt << "\n";
	cout << dto.plus_cnt << "\n";
}