#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100010],b[100010],pr,pv,t,res;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++) b[i]+=b[i-1];
	
	priority_queue<int,vector<int>,greater<int> >q;
	a[n+1]=m;
	pr=0;
	for(int i=0;i<=n;i++)
	{
		pv=pr;
		while(pr<n&&b[pr+1]<a[i+1]) pr++;
		if(pv==pr)
		{
			q.push(a[i+1]-a[i]);
			q.pop();
		}
		else
		{
			q.push(a[i+1]-a[i]);
			t=q.top();
			q.pop();
			t=max(0ll,t-(b[pv+1]-a[i]));
			q.push(t);
			for(int j=pv+2;j<=pr;j++) q.push(0);
		}
	}
	res=0;
	while(!q.empty())
	{
		res+=q.top();
		q.pop();
	}
	cout<<res<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}

/*
3
 3 10
 1 5 9
 1 2 3
 3 10
 1 5 9
 1 1 4
 3 10
 1 5 9
 1 5 10
*/
