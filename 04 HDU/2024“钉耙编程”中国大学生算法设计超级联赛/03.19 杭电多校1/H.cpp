
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,k;
    cin>>n>>k;
    int ans=1;
    for(int i=k-1;i>=0;i--)
    {
        if(n>>i&1) ans*=12;
        else ans*=4;
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