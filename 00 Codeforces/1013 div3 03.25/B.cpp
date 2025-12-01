#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,x,y;
    cin>>n>>x;
    int ans=0;
    vector<int>a;
    for(int i=1;i<=n;i++)
    {
        cin>>y;
        if(y>=x) ans++;
        else a.push_back(y);
    }
    sort(a.begin(),a.end(),greater<int>());
    int cnt=0;
    for(auto i:a)
    {
        cnt++;
        if(cnt*i>=x) 
        {
            ans++;
            cnt=0;
        }
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
