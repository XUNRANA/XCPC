#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    int cnt=0;
    while(n!=1)
    {
        if(n&1) n=(3*n+1)/2;
        else n/=2;
        cnt++;
    }
    cout<<cnt<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}