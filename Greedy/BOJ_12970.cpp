#include <iostream>
#include <string>

using namespace std;
	
string getAnswer(int K, int A, int B)
{
	string ans;
	int a_count(0);
	
	for(int i=B; i>0; i--)
	{
		int quotient = K / i;
		
		K -= quotient * i;
		
		for(int j=0; j<quotient; j++)
		{
			if(a_count >= A)
				continue;
			
			ans += "A";
			a_count++;
		}
		
		ans += "B";
	}
	
	for(int i=a_count; i<A; i++)
		ans += "A";
	
	return ans;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, K;
	cin >> N >> K;
	
	for(int i=0; i<N; i++)
	{
		if(K <= i * (N-i))
		{
			cout << getAnswer(K, i, N-i) << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	
	return 0;
}

