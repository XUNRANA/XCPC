#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    int d=b-a;
    if(d&1) cout<<"no\n";
    else 
    {
        if(d==2)
        {
            if(!a) cout<<"no\n";
            else cout<<"yes\n";
        }
        else cout<<"yes\n";
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
