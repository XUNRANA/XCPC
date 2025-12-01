#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f[1000001];
vector<int>p;
void init()//œﬂ–‘…∏ 
{
	for(int i=2;i<=1e6;i++)
	{
		if(!f[i]) p.push_back(i);
		for(int j=0;j<p.size()&&i*p[j]<=1e6;j++)
		{
			f[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
void solve()
{
	int n,m,l,r;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>l>>r;
		if(r>m||l<1) cout<<"Crossing the line\n";
		else 
		{	
			cout<<upper_bound(p.begin(),p.end(),r)-lower_bound(p.begin(),p.end(),l)<<"\n";
		}
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
