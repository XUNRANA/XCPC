#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f[100000001];
vector<int>p;
void init()//œﬂ–‘…∏ 
{
	for(int i=2;i<=1e8;i++)
	{
		if(!f[i]) p.push_back(i);
		for(int j=0;j<p.size()&&i*p[j]<=1e8;j++)
		{
			f[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
void solve()
{
	int n,q,x;
	cin>>n>>q;
	while(q--)
	{
		cin>>x;
		cout<<p[x-1]<<"\n";
	}
}

signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
