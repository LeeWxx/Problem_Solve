#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool recursion(string T, string S)
{
	if(T.size() == S.size())
	{
		if(T == S)
			return true;
		else
			return false;
	}
	
	if(T[T.size()-1] == 'A')
	{
		if(recursion(T.substr(0, T.size()-1), S))
			return true;
	}
	
	if(T[0] == 'B')
	{
		reverse(T.begin(), T.end());
		if(recursion(T.substr(0, T.size()-1), S))
			return true;
	}	
	
	return false;
}


int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	string S;
	string T;
	
	cin >> S >> T;
	
	bool answer = recursion(T, S);
	
	cout << answer << "\n";
	
}






