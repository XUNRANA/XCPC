#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,f[1000010];
#define P 1000
void init()
{
	f[0]=0;
    f[1]=1;
    n=2;
	while(1) 
	{
		f[n]=(f[n-1]+f[n-2])%P;
		if(f[n-1]==0&&f[n]==1) break;
        n++;
	}
}
void solve()
{
	for(int i=1;i<=4;i++)
	{
		int x;
		cin>>x;
		x%=n-1;
		cout<<f[x]<<"\n";
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
