#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p,l,t;
bool ck(int x)
{
    int cnt=(n+6)/7;
    return x*l+t*min(cnt,2*x)>=p;
}
void solve()
{
    cin>>n>>p>>l>>t;
    int l=1,r=n;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)) r=m-1;
        else l=m+1;
    }
    cout<<n-l<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
