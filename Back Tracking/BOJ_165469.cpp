#include <iostream>

using namespace std;

void print(int output_arr[], int n)
{
	for(int i=0; i<n-1; i++)
		cout << output_arr[i] << " ";
		
	cout << output_arr[n-1] << "\n";  
}

void solve(int idx, int N, int M, bool check_arr[], int output_arr[])
{
	
	if(idx == M)
	{
		print(output_arr, M);
		return;
	}	
	
	for(int i=1; i<=N; i++)
	{
		if(check_arr[i])
			continue;
		
		check_arr[i] = true;
		if(!output_arr[idx])
			output_arr[idx] = i;
		
		solve(idx+1, N, M, check_arr, output_arr);
		
		check_arr[i] = false;
		output_arr[idx] = 0;
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	bool* check_arr = new bool[N];
	int* output_arr = new int[M];
	
	solve(0, N, M, check_arr, output_arr);
	
	delete[] check_arr;
	delete[] output_arr;
}