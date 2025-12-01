#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    if(n<=2) cout<<"1\n";
    else 
    {
        for(int i=61;i>=0;i--)
        if(n>>i&1)
        {
            if(n==(1ll<<i)) cout<<n<<"\n";
            else cout<<(2ll<<i)<<"\n";
            return ;
        }
    }
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
