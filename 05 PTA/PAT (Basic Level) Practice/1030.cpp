#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,p,a[100010];
void solve()
{
    cin>>n>>p;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1,j=1;j<=n;j++)
    {
        while(a[j]>a[i]*p) i++;
        ans=max(ans,j-i+1);
    }
    cout<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

