#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b;
    int f=0;
    while(cin>>a>>b)
    {
        if(b!=0)
        {
            if(f) cout<<" ";
            cout<<a*b<<" "<<b-1;
            f=1;
        }
    }
    if(!f) cout<<"0 0\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}