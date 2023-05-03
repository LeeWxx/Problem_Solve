#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_INPUT_VALUE = 8;

bool checked_arr[MAX_INPUT_VALUE] = {false, };
int input_arr[MAX_INPUT_VALUE] = {0, };

bool asc(int a, int b){ 
  return a < b; 
} 

void print(int output_arr[], int M)
{
	for(int i=0; i<M-1; i++)
		cout << output_arr[i] << " ";
	
	cout << output_arr[M-1] << "\n";
}

void solve(int idx, int N, int M, int output_arr[],int last_input_idx)
{
	if(idx == M)
	{
		print(output_arr, M);
		return;
	}	
	
	for(int i=last_input_idx; i<N; i++)
	{
		if(checked_arr[i])
			continue;
		
		checked_arr[i] = true;
		
		if(!output_arr[idx])
			output_arr[idx] = input_arr[i];
	
		solve(idx+1, N, M, output_arr, i);
		
		output_arr[idx] = 0;
		checked_arr[i] = false;
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	for(int i=0; i<N; i++)
		cin >> input_arr[i];
	
	sort(input_arr, input_arr+N, asc);
	
	int* output_arr = new int[M];
	
	solve(0, N, M, output_arr, 0);
	
	delete[] output_arr;
	
}