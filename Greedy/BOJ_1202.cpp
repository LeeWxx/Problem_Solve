#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct Jewel
{
    int v;
    int m;
};

const int MAX_INPUT = 300000;

Jewel jewel_arr[MAX_INPUT];

bool compare(Jewel a, Jewel b)
{
	return a.v > b.v;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, K;
	cin >> N >> K;
	for(int i=0; i<N; i++)
	{
		Jewel jewel;
		cin >> jewel.m;
		cin >> jewel.v;
		
		jewel_arr[i] = jewel;
	}
	
	sort(jewel_arr, jewel_arr + N, compare);
	
	multiset<int> mset;
	
	for(int i=0; i<K; i++)
	{
		int c;
		cin >> c;
		mset.insert(c);
	}
	
	long long sum(0);
	int cnt(0);
	multiset<int>::iterator iter;
	for(int i=0; i<N; i++)
	{
		int m = jewel_arr[i].m;
		iter = mset.lower_bound(m);
		
		if(iter == mset.end())
			continue;
		
		mset.erase(iter);
		sum += jewel_arr[i].v;
		cnt++;
		
		if(cnt == K)
			break;
	}
	
	cout << sum << endl;
	
	
 	return 0;
}