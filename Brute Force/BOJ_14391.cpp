#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int input_arr[4][4];

int getVerticalSum(int bit_mask, int N, int M)
{
	int sum(0);

	for(int j=0; j<M; j++)
	{
		int vertical_sum(0);
		int cnt(0);

		for(int k=N-1; k>=0; k--)
		{
			if(1 << ((k * M) + j) & bit_mask)
			{
				vertical_sum += pow(10,cnt) * input_arr[k][j];
				cnt++;
			}
			else
				cnt = 0;
		}
		
		sum += vertical_sum;
	}
	
	return sum;
}

int getHorizontalSum(int bit_mask, int N, int M)
{
	int sum(0);
	for(int j=0; j<N; j++)
	{
		int horizontal_sum(0);
		int cnt(0);
		for(int k=M-1; k>=0;k--)
		{
			if(1 << ((j*M) + k) & ~(bit_mask))
			{
				horizontal_sum += pow(10,cnt) * input_arr[j][k];
				cnt++;
			}
			else
				cnt = 0;
		}
		sum += horizontal_sum;
	}
	
	return sum;
}

int solve(int N, int M)
{
	int max_sum(0);

	for(int i=0; i<(1 << (N*M)); i++)
	{
		int vertical_sum = getVerticalSum(i, N, M);
		int horizontal_sum = getHorizontalSum(i, N, M);
		
		max_sum = max(max_sum, vertical_sum + horizontal_sum);
	}
	return max_sum;
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
			input_arr[i][j] = s.at(j) - '0';	
		}
	}
	
	int result = solve(N, M);
	cout << result << endl;
}