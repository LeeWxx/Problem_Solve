#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int solve(int* arr, int N)
{
	
	int sum(0);

	for(int i=0; i<N-1; i++)
	{
		int value = (arr[i] - arr[i+1]);
		if(value < 0)
			value *= -1;
		sum += value;
	}
	
	return sum;
}

bool next_permutaion(int* arr, int N)
{
	int first_idx(-1);
	
	for(int i=N-2; i>=0; i--)
	{
		if(arr[i] < arr[i+1])
		{
			first_idx = i;
			break;
		}
	}
	
	if(first_idx == -1)
		return false;
	
	for(int i=N-1; i>first_idx; i--)
	{
		if(arr[first_idx] < arr[i])
		{
			int temp = arr[i];
			arr[i] = arr[first_idx];
			arr[first_idx] = temp;
			
			break;
		}
	}
	
	int* temp = new int[(N-1) - first_idx];

	for(int i=N-1; i>first_idx; i--)
	{
		temp[(N-1) - i] = arr[i];
	}
	
	for(int i=first_idx+1; i<N; i++)
		arr[i] = temp[i - (first_idx+1)];
	
	return true;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	
	int* arr = new int[N];
	
	for(int i=0; i<N; i++)
		cin >> arr[i];
	
	sort(arr, arr+N);
	
	
	int output(INT_MIN);
	bool result = true;
	while(result)
	{
		output = max(solve(arr, N), output);
		result = next_permutaion(arr, N);
	}
	
	delete[] arr;
	
	cout << output << endl; 
}