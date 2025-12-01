#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int g=0;
    for(int i=2;i<=n;i++) if(a[i]%a[1]==0) g=__gcd(g,a[i]);
    if(g==a[1]) cout<<"Yes\n";
    else cout<<"No\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
