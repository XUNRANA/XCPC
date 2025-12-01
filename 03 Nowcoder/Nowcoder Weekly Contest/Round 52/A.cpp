#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int z;
    cin>>z;
    if(z==2||z==1)
    {
        cout<<"NO\n";
        return ;
    }
    else cout<<"YES\n"<<1<<" "<<z-1<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
