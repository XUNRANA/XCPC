#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,x;
    map<int,int>mp;
    int cnt=0;
    cin>>n;//20250103
    int ans=1e9;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        mp[x]++;
        if(x==0&&mp[x]==3) cnt++;
        else if(x==1&&mp[x]==1) cnt++;
        else if(x==2&&mp[x]==2) cnt++;
        else if(x==3&&mp[x]==1) cnt++;
        else if(x==5&&mp[x]==1) cnt++;
        if(cnt==5) ans=min(ans,i);
    }
    if(ans==1e9) ans=0;
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
