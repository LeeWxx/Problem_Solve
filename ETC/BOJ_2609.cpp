#include <iostream>

using namespace std;


int getLCM(int a, int b, int gcd)
{
	int lcm = (a * b) / gcd;
	return lcm;
}

int getGCD(int a, int b)
{	
	if(b == 0)
		return a;
	
	int r = a % b;
	return getGCD(b, r);
}
	
int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a,b; 
	cin >> a >> b;

	int gcd = getGCD(a, b);
	int lcm = getLCM(a, b, gcd);
	
	cout << gcd << endl;
	cout << lcm << endl;
}