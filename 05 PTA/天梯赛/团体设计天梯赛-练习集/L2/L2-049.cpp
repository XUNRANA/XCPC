#include <bits/stdc++.h>
using namespace std;

set<int>a[1010];
void solve()
{
	int n,m,k,ans,q,x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>x;
			a[i].insert(x);
		}
	}
	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		ans=0;
		for(int i=1;i<=n;i++) if(a[i].count(x)&&a[i].count(y)) ans++;
		cout<<ans<<"\n";
	}
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

