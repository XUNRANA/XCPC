#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,x,ans=0;
	cin>>n>>x;
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            if(i<=n) ans++;
            if(i!=x/i&&x/i<=n) ans++;
        }
    }
    if(ans&1) cout<<"ON\n";
    else cout<<"OFF\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
