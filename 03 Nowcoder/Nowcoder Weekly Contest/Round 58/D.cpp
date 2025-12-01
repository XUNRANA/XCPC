#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int ck()
{
    int cnt=0;
    while(n)
    {
        cnt=max(cnt,n%k);
        n/=k;
    }
    return cnt;
}

void solve()
{
	cin>>n>>k;
    if(k==1) cout<<1<<"\n";
    else cout<<ck()<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
