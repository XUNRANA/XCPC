#include <bits/stdc++.h>
using namespace std;
int n,x;
int main()
{
	priority_queue<int,vector<int> >q1;//大根堆 
	priority_queue<int,vector<int>,greater<int> >q2;//小根堆 
	cin>>n>>x;
	q1.push(x);
	cout<<q1.top()<<"\n";
	for(int i=2;i<=n;i++)
	{
		cin>>x;
		if(x>q1.top()) q2.push(x);
		else q1.push(x);
		while(abs(q1.size()-q2.size())>1)
		{
			if(q1.size()>q2.size())
			{
				q2.push(q1.top());
				q1.pop();
			}
			else
			{
				q1.push(q2.top());
				q2.pop();
			}
		}
		if(i&1) cout<<(q1.size()>q2.size()? q1.top():q2.top())<<"\n";
	}	
}
