#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1)
    {
        cout<<"-1\n";
        return ;
    }
	if(n&1) cout<<n/2+1<<"\n";
	else cout<<n/2<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
