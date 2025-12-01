#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    s=" "+s;
    int up=0;
    int down=0;
    int ans=0;
    for(int i=1;i<=n;i++) 
    {
        if(s[i]=='0')
        {
            up+=i-1;
            down+=n-i;
        }
        else
        {
            up=down+1;
            down=0;
        }
        ans=max(ans,up);
        ans=max(ans,down);
    }
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
