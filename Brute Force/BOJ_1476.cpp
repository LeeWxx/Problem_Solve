#include <iostream>
using namespace std;


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int target_E,target_S,target_M;
	cin >> target_E >> target_S >> target_M;
	
	int e(1);
	int s(1);
	int m(1);
	
	bool check = false;
	
	int output(1);
	while(!check)
	{
		if(e != target_E || s != target_S || m != target_M)
		{
			e++;
			if(e > 15)
			{
				e = 1;
			}
			
			s++;
			if(s > 28)
			{
				s = 1;
			}
			
			m++;
			if(m > 19)
			{
				m = 1;
			}
			
			output++;
		}
		else
			check = true;
			
	}
	
	cout << output << endl; 
}