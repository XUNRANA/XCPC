#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[7],s;
void solve()
{
    for(int i=1;i<=6;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    if(a[1]*30<s) cout<<"Yes\n";
    else cout<<"No\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
