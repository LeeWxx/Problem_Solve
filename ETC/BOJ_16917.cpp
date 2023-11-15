#include <iostream>
#include <string>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	
	int cost(0);
	
	if(A + B >= 2 * C)
	{
		int prc = min(X, Y);
		cost += (2 * C) * prc;
		
		X -= prc;
		Y -= prc;
	}
	
	if(X > 0)
	{
		int prc = X;
		if(A > 2 * C)
			cost += (2 * C) * prc;
		else
			cost += A * prc;
	}
	
	if(Y > 0)
	{
		int prc = Y;
		if(B > 2 * C)
			cost += (2 * C) * prc;
		else
			cost += B * prc;
	}
	
	cout << cost << endl;
}



