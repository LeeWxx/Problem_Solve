#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_INPUT = 10000;
int output_arr[8];

void print(int size)
{
	for(int i=0; i<size-1; i++)
		cout << output_arr[i] << " ";
	
	cout << output_arr[size-1] << "\n";
}

void solve(int index, int N, int M, int* input_arr, int* cnt_arr)
{
	if(index == M)
		print(M);
	
	for(int i=0; i<N; i++)
	{
		if(cnt_arr[i] > 0)
		{
			output_arr[index] = input_arr[i];
			cnt_arr[i]--;
			
			solve(index+1, N, M, input_arr, cnt_arr);
			cnt_arr[i]++;
		}
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
	int* cnt_arr = new int[N] {0, };
	
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
				cnt_arr[j]++;
				check = true;
			}
		}
		
		if(!check)
		{
			input_arr[cnt] = temp_arr[i];
			cnt_arr[cnt]++;
			cnt++;
		}
	}
	
	
	solve(0, N, M, input_arr, cnt_arr);

}