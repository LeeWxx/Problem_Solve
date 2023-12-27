#include <iostream>
#include <queue>

using namespace std;


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 

	int N;
	cin >> N;
	
	priority_queue<int> card_que;

	for(int i=0; i<N; i++)
	{
		int n;
		cin >> n;
		n *= -1;
		
		card_que.push(n);
	}
	
	int cnt = 0;
	while(!card_que.empty())
	{
		int first = card_que.top();
		card_que.pop();
		
		if(card_que.empty())
			break;
		
		int second = card_que.top();
		card_que.pop();
		
		first *= -1;
		second *= -1;
		
		cnt += first;
		cnt += second;
	
		
		card_que.push((first + second) * -1);
	}
	
	cout << cnt << "\n";
}