#include <bits/stdc++.h>
using namespace std;
int n,m,q,p,k,s[100010],d[100010];
vector<int>g[100010];
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++) cin>>s[i];
	for(int i=1;i<=q;i++)
	{
		cin>>p>>k;
		g[p].push_back(k);
	}
	for(int i=1;i<=m;i++)
	{
		if(g[i].size()==0) continue;
		sort(g[i].begin(),g[i].end());
		int l=0,r=0;
		for(auto j:g[i])
		{
			if(!l) 
			{
				l=j;
				r=j+s[i]-1;
				r=min(r,n+1);
        if(r==n+1) break;
			}
			else
			{
				if(j>r)
				{
					d[l]++;
					d[r+1]--;
					l=j;
					r=j+s[i]-1;
					r=min(r,n+1);
          if(r==n+1) break;
				}
				else 
				{
					r=max(r,j+s[i]-1);
					r=min(r,n+1);
					if(r==n+1) break;
				}
			}
		} 
		d[l]++;
		d[r+1]--;
	}
	for(int i=1;i<=n;i++) d[i]+=d[i-1];
	for(int i=1;i<=n;i++) cout<<d[i]<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
