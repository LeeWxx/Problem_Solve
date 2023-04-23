#include <iostream>
using namespace std;


int getGCD(int a,int b)
{
	if(b == 0)
		return a;
	
	return getGCD(b, a % b);
}

int getLCM(int a, int b, int gcd)
{
	int lcm = (a * b) / gcd;
	return lcm;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long input_count;
	cin >> input_count; 
	
	while(input_count--)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		
		int a(x);
		int b(y);
		
		int output;
		bool is_found = false;
		
		int gcd = getGCD(M, N);
		int lcm = getLCM(M, N, gcd);
		
		while(a <= lcm && b <= lcm)
		{
			
			if(a == b)
			{
				output = a;
				is_found = true;
				break;
			}
			else if(a < b)
				a += M;
			else
				b += N;
		}
		
		if(!is_found)
			cout << -1 << "\n";
		else 
			cout << output << "\n";
	}
}