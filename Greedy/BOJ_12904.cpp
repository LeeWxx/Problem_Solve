#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
	
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string S, T;
	cin >> S >> T;
	
	while(T.size() > S.size())
	{
		char ch = T[T.size()-1];
		T.pop_back();
		
		if(ch == 'B')
			reverse(T.begin(), T.end());
	}
	
	if(T == S)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	
	return 0;
}

