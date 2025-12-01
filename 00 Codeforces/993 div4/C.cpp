#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int m,a,b,c;
    cin>>m>>a>>b>>c;
    int ta=min(m,a);
    int tb=min(m,b);
    int tc=min(c,m-ta+m-tb);
    cout<<ta+tb+tc<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
