#include <iostream>

using namespace std;

int getGCD(int a, int b)
{
	if(b==0)
		return a;
	
	return getGCD(b, a%b);
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int brother_count;
	cin >> brother_count;
	
	int s_location;
	cin >> s_location;
	
	int *brother_location_arr = new int[brother_count];
	
	for(int i = 0; i< brother_count; i++)
	{
		int x;
		cin >> x;
		
		brother_location_arr[i] = x - s_location;
		
		if(brother_location_arr[i] < 0)
			brother_location_arr[i] *= -1;
	}
	
	int gcd = brother_location_arr[0];
	
	for(int i=1; i<brother_count; i++)
		gcd = getGCD(gcd, brother_location_arr[i]);
	
	cout << gcd << endl;
	
	
}