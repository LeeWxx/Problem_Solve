#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_INPUT = 100;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	int* t_arr = new int[N];
	
	for(int i=0; i<N; i++)
	{
		cin >> t_arr[i];
	}
	
	sort(t_arr, t_arr+N);
	
	int sum(0);
	
	for(int i=0; i<N; i++)
	{
		sum += (N - i) * t_arr[i];
	}
	
	cout << sum << endl;
	
	delete[] t_arr;
	
 	return 0;
}