#include <iostream>

using namespace std;


int gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	
	int ret = gcd(b, a%b);
	return ret;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	int input_count;
	cin >> input_count;
	
	while(input_count--)
	{
		int x;
		cin >> x;
		
		long long sum(0);
		int* arr = new int[x];
		
		for(int i = 0; i<x; i++)
		{
			cin >> arr[i];
		}
		
		
		for(int i = 0; i<x; i++)
		{
			for(int j=i+1; j<x; j++)
			{
				sum += gcd(arr[i], arr[j]);
			}
		}
		
		cout << sum << '\n';
		
		delete[] arr;
		arr = NULL;
	}
	
	cout << endl;
}