#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int m,n,a,b,c,x;
	cin>>m>>n>>a>>b>>c;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			if(j!=1) printf(" ");
			if(x>=a&&x<=b) printf("%03d",c);
			else printf("%03d",x);
		}
		printf("\n");
	}
	
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
