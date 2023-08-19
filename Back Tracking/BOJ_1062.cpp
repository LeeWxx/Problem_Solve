#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX_N_INPUT = 50;
const int ALPHABET_COUNT =26;
const int CHECK_ALPHABET_COUNT =21;
int idx_arr[ALPHABET_COUNT];

void setIdx()
{
	memset(idx_arr, -1, sizeof(int) * ALPHABET_COUNT);
	
	int val(0);
	
	for(int i=0; i<ALPHABET_COUNT; i++)
	{
		char ch = (char) (i + 97);
		if(ch == 'a' || ch == 't' || ch == 'i' || ch == 'c' || ch == 'n')
			continue;
		
		idx_arr[ch - 'a'] = val++;
	}
}

int getBitCnt(int v){
   int cnt = 0;
   while (v){
       cnt += (v & 1);
       v >>= 1;
   }
   return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, K;
	cin >> N >> K;
	
	if(K <= 4)
	{
		cout << 0 << endl;
		return 0;
	}
	
	setIdx();
	
	string *input = new string[N];
	
	for(int i=0; i<N; i++)
		cin >> input[i]; 
	
	int result(0);
	int max_num = (1<< CHECK_ALPHABET_COUNT) - 1;
	for(int i=0; i<= max_num; i++)
	{
		if(getBitCnt(i) > K-5)
			continue;
		
		int cnt(0);
		
		for(int j=0; j<N; j++)
		{		
			bool is_checked = true;
			
			for(int k=3; k<input[j].size()-4; k++)
			{
				char ch = input[j].at(k);
				if(ch == 'a' || ch == 't' || ch == 'i' || ch == 'c' || ch == 'n')
					continue;
		
				if(!(i & (1 << idx_arr[ch - 'a'])))
				{
					is_checked = false;
					break;
				}
			}
			
			if(is_checked)
			{
				cnt++;
				continue;
			}
		}
		
		result = max(cnt, result);
	}
	
	cout << result << endl;
	
	delete[] input;
}