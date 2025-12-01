#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,q;
int a[100010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>q;
	while(q--)
	{
		map<int,int>mp;
		while(1)
		{
			int x;
			cin>>x;
			if(!x) break;
			mp[a[x]]++;
		}
		int f=0;
		for(auto i:mp) 
		{
			if(f) cout<<" ";
			cout<<"B"<<i.first<<"-"<<i.second;
			f=1;
		}
		cout<<"\n";
	}

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
