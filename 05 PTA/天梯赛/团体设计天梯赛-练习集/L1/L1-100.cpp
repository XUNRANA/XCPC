#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,m,s=0,x;
	cin>>n>>m;
	for(int i=1;i<=m;i++) 
	{
		cin>>x;
		s+=x;
	}
	cout<<max(0ll,s-(m-1)*n)<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

