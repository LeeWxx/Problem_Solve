#include <iostream>
#include <string>

using namespace std;

const int MAX_INPUT = 10000;
int count[MAX_INPUT+1];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		int x;
		cin >> x;
		count[x]++;
	}
	
	for(int i=1; i<=MAX_INPUT; i++)
		for(int j=0; j<count[i]; j++)
			cout << i << "\n";
}






