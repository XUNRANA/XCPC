#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[102][22],t;
void solve()
{
	cin>>n>>m;
    set<int>s,s1;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    
    cin>>t;
    
    for(int j=1;j<=m;j++) s.insert(a[1][j]);

    
    for(int i=2;i<=n;i++)
    {
        s1.clear();
        for(int j=1;j<=m;j++) 
        {
            for(auto k:s) s1.insert(k+a[i][j]);
        }
        s=s1;
    }
    int ans=5000;
    for(auto i:s) ans=min(ans,abs(i-t));
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
