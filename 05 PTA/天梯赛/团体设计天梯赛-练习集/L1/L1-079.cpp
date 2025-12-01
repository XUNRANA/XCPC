#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
	map<int,int>cnt;
	int mi=1e6;
	int mx=1;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		mx=max(mx,x);
		mi=min(mi,x);
		cnt[x]++;
	}
	cout<<mi<<" "<<cnt[mi]<<"\n";
	cout<<mx<<" "<<cnt[mx]<<"\n";
	
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

