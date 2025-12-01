#include <bits/stdc++.h>
using namespace std;
#define int long long

#define P 1000000007
void solve()
{
    string s;
    cin>>s;
    int p=0;
    int pa=0;
    int ans=0;
    for(auto i:s)
    {
        if(i=='P') p++;
        else if(i=='A') pa+=p;
        else if(i=='T') ans+=pa;
        p%=P;
        pa%=P;
        ans%=P;
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
