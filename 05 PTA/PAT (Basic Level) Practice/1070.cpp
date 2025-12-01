#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[10010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    double ans=a[1];
    for(int i=2;i<=n;i++) 
    {
        ans=(ans+a[i])/2;
    }
    cout<<(int)ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
