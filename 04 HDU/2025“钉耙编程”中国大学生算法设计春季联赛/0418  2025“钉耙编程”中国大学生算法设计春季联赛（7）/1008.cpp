#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[6];
void solve()
{
    int ans=1;
    for(int i=1;i<=5;i++)
    {
    	cin>>a[i];
    	if(i<=3) ans=ans*a[i];
	}
	int res=0;
	res=ans*a[4]*a[5]+ans*a[4]*(a[4]-1)/2;
	cout<<res<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
