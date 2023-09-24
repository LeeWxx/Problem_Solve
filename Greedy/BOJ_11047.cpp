#include <iostream>

using namespace std;
const int MAX_INPUT = 100;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, K;
	cin >> N >> K;
	
	int* coin_arr = new int[N];
	
	for(int i=0; i<N; i++)
		cin >> coin_arr[i];
	
	int cnt(0);
	int sum(0);
	
	for(int i=N-1; i>=0; i--)
	{
		if(coin_arr[i] > K - sum)
			continue;
		
		int c = (K - sum) / coin_arr[i];
		
		cnt += c;
		sum += coin_arr[i] * c;
	}
	
	cout << cnt << endl;
	
	delete[] coin_arr;
	
 	return 0;
}