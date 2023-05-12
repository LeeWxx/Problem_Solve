#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_INPUT_COUNT = 7;

int output_arr[MAX_INPUT_COUNT] {0, };

void print(int M)
{
	for(int i=0; i<M-1; i++)
		cout << output_arr[i] << " ";
	cout << output_arr[M-1] << "\n";
}

void solve(int index, int N, int M, int input_arr[])
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
	
	int* input_arr = new int[N];
	
	for(int i=0; i<N; i++)
		cin >> input_arr[i];
	
	sort(input_arr, input_arr+N); 
	
	solve(0, N, M, input_arr);
	
	delete[] input_arr;
}