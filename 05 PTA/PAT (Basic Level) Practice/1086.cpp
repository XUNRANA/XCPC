#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b;
    cin>>a>>b;
    a*=b;
    int p=0;
    while(a)
    {
        if(a%10) p=1;
        if(p) cout<<a%10;
        a/=10;
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
