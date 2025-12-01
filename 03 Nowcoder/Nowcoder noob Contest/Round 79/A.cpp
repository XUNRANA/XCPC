#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt;
void solve()
{
    cin>>n;
    while(n&1)
    {
        cnt++;
        n/=10;
    }
    cout<<cnt;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
