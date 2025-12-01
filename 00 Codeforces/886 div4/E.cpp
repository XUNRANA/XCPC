#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,c,s[200010];
bool ck(int x)
{
    __int128 res=0;
    for(int i=1;i<=n;i++)
    {
        res+=(s[i]+2*x)*(s[i]+2*x);
        if(res>=c) return 1;
    }
    return 0;
}
void solve()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++) cin>>s[i];
    int l=1,r=1e9;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)) r=m-1;
        else l=m+1;
    }
    cout<<l<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
