#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	cin >> m >> n;
	
	bool *check_arr = new bool[n] {false, };
	
	for(int i = 2; i <= n; i++)
	{
		if(check_arr[i] == false)
		{
			for(int j = i*2; j <= n; j+=i)
				check_arr[j] = true;	
			
			if(i >= m)
				cout << i << '\n';
		}
	}
	
	cout << endl;
	
	delete[] check_arr;
}