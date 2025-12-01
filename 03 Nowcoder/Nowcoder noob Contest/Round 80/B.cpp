#include <bits/stdc++.h>
using namespace std;
#define int long long
int s,mi=1e9,n,t;
void solve()
{
    int n,m,k,t,ans=0;
    cin>>n>>m>>k;
    vector<int>c(m+1);
    for(int i=0;i<n;i++)
    {
        cin>>t;
        c[t]++;
        ans=max(c[t],ans);
    }
    if(n-k>=ans) cout<<ans;
    else cout<<n-k;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
