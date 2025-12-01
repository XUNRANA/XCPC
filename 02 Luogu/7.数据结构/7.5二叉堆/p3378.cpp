#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,op,x;
	cin>>n;
	//priority_queue<int> q;//大根堆、堆顶最大 
	priority_queue<int,vector<int>,greater<int> >q;
	while(n--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x;
			q.push(x);
		}
		else if(op==2) cout<<q.top()<<"\n";
		else q.pop();
	}
} 
