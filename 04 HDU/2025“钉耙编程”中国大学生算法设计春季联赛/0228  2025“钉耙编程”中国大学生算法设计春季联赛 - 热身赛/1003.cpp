#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,x;
    cin>>n;
    int sa=0,sb=0,sc=0;
    for(int i=1;i<=n;i++) cin>>x,sa+=x;
    for(int i=1;i<=n;i++) cin>>x,sb+=x;
    for(int i=1;i<=n;i++) cin>>x,sc+=x;
    if((sc-sb)%sa==0) cout<<(sc-sb)/sa<<"\n";
    else cout<<"-1\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
