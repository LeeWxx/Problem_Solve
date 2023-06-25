#include <iostream>
#include <limits.h>

using namespace std;


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int M;
	cin >> M;
	
	int S = 0;
	
	while(M--)
	{
		string instr;
		cin >> instr;
		
		int x;
		if(instr != "all" && instr != "empty")
			cin >> x;	
		
		if(instr == "add")
		{
			S |= (1 << x);
		}
		else if(instr == "remove")
		{
			S &= ~(1 << x);
		}
		else if(instr == "check")
		{
			bool ans = S & (1 << x);
			cout << ans << "\n";
		}
		else if(instr == "toggle")
		{
			S ^= (1 << x);
		}
		else if(instr == "all")
		{
			S |= INT_MAX;
		}
		else if(instr == "empty")
		{
			S &= 0;
		}		
	}
}