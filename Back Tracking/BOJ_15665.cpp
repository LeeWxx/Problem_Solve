#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_INPUT = 10000;
int output_arr[7];

void print(int size)
{
	for(int i=0; i<size-1; i++)
		cout << output_arr[i] << " ";
	
	cout << output_arr[size-1] << "\n";
}

void solve(int index, int N, int M, int* input_arr)
{
	if(index == M)
	{
		print(M);
		return;
	}
	
	for(int i=0; i<N; i++)
	{
		output_arr[index] = input_arr[i];	
		solve(index+1, N, M, input_arr);
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;
	
	int* temp_arr = new int[N];
	
	for(int i=0; i<N; i++)
		cin >> temp_arr[i];
	
	sort(temp_arr, temp_arr+N);
	
	int* input_arr = new int[N];
	for(int i=0; i<N; i++)
		input_arr[i] = MAX_INPUT + 1;
	
	int cnt(0);
	for(int i=0; i<N; i++)
	{
		bool check = false;
		for(int j=0; j<i; j++)
		{
			if(input_arr[j] == temp_arr[i])
			{
				check = true;
				break;
			}
		}
		
		if(!check)
		{
			input_arr[cnt++] = temp_arr[i]; 
		}
	}
	
	solve(0, cnt, M, input_arr);
	
	delete[] temp_arr;
	delete[] input_arr;
}