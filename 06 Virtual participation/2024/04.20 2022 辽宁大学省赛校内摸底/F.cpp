#include <bits/stdc++.h>
using namespace std;
#define N 2010
#define int long long
int n,s,u,cost;
void solve()
{
	cin>>n;
	vector<int>vt(n),fa(n,-1),sta,x(n),y(n),c(n),k(n);
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<n;i++) cin>>k[i];
	s=0;
	for(int i=0;i<n;i++)
	{
		u=-1;
		for(int j=0;j<n;j++) if(!vt[j]&&(u==-1||c[j]<c[u])) u=j;
		vt[u]=1;
		s+=c[u];
		if(fa[u]==-1) sta.push_back(u);
		for(int j=0;j<n;j++)
		{
			if(!vt[j])
			{
				cost=(k[u]+k[j])*(abs(x[u]-x[j])+abs(y[u]-y[j]));
				if(cost<c[j])
				{
					c[j]=cost;
					fa[j]=u;
				}
			}
		}
	}
	cout<<s<<"\n";
	cout<<sta.size()<<"\n";
	for(auto i:sta) cout<<i+1<<" ";
	cout<<"\n";
	cout<<n-sta.size()<<"\n";
	for(int i=0;i<n;i++) if(fa[i]!=-1) cout<<i+1<<" "<<fa[i]+1<<"\n";
}                  
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
