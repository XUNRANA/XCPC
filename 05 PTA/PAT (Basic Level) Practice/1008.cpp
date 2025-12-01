#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[210];
void solve()
{
    int n,m;
    int f=0;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=n;i<2*n;i++) a[i]=a[i-n];
    for(int i=n-m%n,cnt=0;cnt<n;cnt++,i++) 
    {
        if(f) cout<<" ";
        cout<<a[i];
        f=1;
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}