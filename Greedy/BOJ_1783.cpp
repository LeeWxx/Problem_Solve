#include <iostream>

using namespace std;
	
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;
	
	if(N == 1)
	{
		cout << 1 << endl;
	}
	else if(N == 2)
	{
		if(M >= 7)
			cout << 4 << endl;
		else
			cout << (M+1) / 2 << endl;
	}
	else
	{
		if(M <= 4)
			cout << M << endl;
		else if(M < 7)
			cout << (M+1) / 2 + 1 << endl;
		else
			cout << M - 2 << endl;
	}
	
	return 0;
}

