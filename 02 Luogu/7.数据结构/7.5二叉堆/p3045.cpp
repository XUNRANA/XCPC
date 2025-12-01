#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 50010
int n,k,m,s,ans,t1,t2,f[N];
priority_queue<int,vector<int>,greater<int> >q1;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q2,q3;
struct node
{
	int p,c;
}a[N];
bool cmp(node a1,node a2)
{
	return a1.c<a2.c;
}
signed main()
{
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++) cin>>a[i].p>>a[i].c;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=k;i++)
	{
		s+=a[i].c;
		if(s>m)
		{
			cout<<i-1;
			return 0;
		}
		q1.push(a[i].p-a[i].c);
	}
	if(k==n)
	{
		cout<<n;
		return 0;
	}
	for(int i=k+1;i<=n;i++) 
	{
		q2.push(make_pair(a[i].p,i));
		q3.push(make_pair(a[i].c,i));
	}
	ans=k;
	for(int i=k+1;i<=n;i++)
	{
		while(f[q2.top().second]) q2.pop();
		while(f[q3.top().second]) q3.pop();
		t1=q1.top()+q3.top().first;
		t2=q2.top().first;
		if(t1<t2)
		{
			s+=t1;
			q1.pop();
			q1.push(a[q3.top().second].p-a[q3.top().second].c);
			f[q3.top().second]=1;
			q3.pop();
		}
		else
		{
			s+=t2;
			f[q2.top().second]=1;
			q2.pop();
		}
		ans++;
		if(s>m)
		{
			cout<<ans-1;
			return 0;
		}
	}
	cout<<n;
}
