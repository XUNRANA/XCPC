#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,d[100010],t[100010],q,t1,x;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>d[i];
	for(int i=1;i<=m;i++) cin>>t[i];
	cin>>q;
	while(q--)
	{
		cin>>t1>>x;
		t1-=d[x];
		int i=lower_bound(t+1,t+1+m,t1)-t;
		if(t[i]<t1) cout<<"TNT\n";
		else cout<<t[i]-t1<<"\n";
	}

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
