#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,t2,t1,a[100010],b[100010]; 
vector<int>g[100010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],g[i].clear();
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(b+1,b+1+n);
	for(int i=2;i<=n;i++) b[i]+=b[i-1];
	priority_queue<int,vector<int>,less<int> >q;//Ωµ–Ú∂”¡– 
	a[n+1]=m;
	ans=0;
	g[0].clear();
	for(int i=0,j=1;i<=n;i++)
	{
		while(j<=n&&b[j]>=a[i]&&b[j]<a[i+1]) g[i].push_back(b[j++]);
	}
	for(int i=n;i>=0;i--)
	{
		if(g[i].size())
		{
			int l=g[i].size()-1;
			int fx=0;
			while(l--) 
			{
				if(q.size()) {ans+=q.top();q.pop();}
				else 
				{
					ans+=a[i+1]-g[i][0];
					q.push(g[i][0]-a[i]);
					fx=1;
					break;
				}
			}
			if(fx==1) continue;
			if(q.size())
			{
				if(a[i+1]-g[i][0]>q.top()) 
				{
					ans+=a[i+1]-g[i][0];
					int t=q.top();
					t+=g[i][0]-a[i];
					q.pop();
					q.push(t);
				}
				else 
				{
					ans+=q.top();
					q.pop();
					q.push(a[i+1]-a[i]);
				}
			}
			else 
			{
				ans+=a[i+1]-g[i][0];
				q.push(g[i][0]-a[i]);
			}
		}
		else q.push(a[i+1]-a[i]);
	}
	cout<<ans<<"\n";
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t1;
	while(t1--) solve();
}

