#include <bits/stdc++.h>
using namespace std;
int n,x,a,b,ans;
int main()
{
	priority_queue<int,vector<int>,greater<int> >q;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x,q.push(x);
	while(q.size()>=2)
	{
		a=q.top();
		q.pop();
		b=q.top();
		q.pop();
		q.push(a+b);
		ans+=a+b;
	}
	cout<<ans;
}
