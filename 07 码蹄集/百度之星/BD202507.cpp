#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,s;
    cin>>n>>s;
    int ans=s;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>=ans) ans=(ans+x+1)/2;
    }
    cout<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
