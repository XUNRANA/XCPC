#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n,x,y;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		ans=max(ans,x*x+y*y);
	}
	printf("%.2f",sqrt(ans));
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
