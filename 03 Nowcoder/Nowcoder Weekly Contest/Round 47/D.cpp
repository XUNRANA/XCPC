#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r,m;
int ck(int x)
{
    x-=(x/3+x/10+(x%10>=3)-((x/3)/10+((x/3)%10>=1)));
    if(n<=x) return 1;
    return 0;
}
void solve()
{
    cin>>n;
    l=1,r=1e18;
    while(l<=r)
    {
        m=l+r>>1;
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
