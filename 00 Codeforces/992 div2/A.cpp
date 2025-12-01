#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,k;
    cin>>n>>k;
    map<int,vector<int>>mp;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp[x%k].push_back(i);
    }
    for(auto i:mp)
    {
        if(i.second.size()==1)
        {
            cout<<"YES\n";
            cout<<i.second[0]<<"\n";
            return ;
        }
    }
    cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
