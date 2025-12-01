#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		double x;
		cin>>x;
		if(x<m) printf("On Sale! %.1f\n",x);
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

