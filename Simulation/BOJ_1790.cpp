#include <iostream>
#include <string>

using namespace std;

int getLength(int N)
{
	int length(0);
	
	for(int start = 1, len = 1; start <= N; start *= 10, len ++)
	{
		int end = (start * 10) - 1;
		
		if(end > N)
			end = N;
		
		length += (end - start + 1) * len;
	}
	
	return length;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	int N, K;
	cin >> N >> K;
	
	int left(1);
	int right(N);
	
	int answer(-1);
	
	while(left <= right)
	{
		int mid = (left + right) / 2;
		int len = getLength(mid);
		
		if(len < K)
			left = mid + 1;
		else
		{
			right = mid - 1;
			
			string str = to_string(mid);
			int size =  str.size();
			
			if((len - K) < size)
			{
				int idx = size - (len - K) - 1;
				answer = str.at(idx) - '0';
				break;
			}
		}	
	}
	
	cout << answer << endl;
	
}






