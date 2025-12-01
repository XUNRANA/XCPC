#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int x,y;
    cin>>x>>y;
    cout<<max(y-x,0ll)<<"\n";

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
