#include <bits/stdc++.h>
using namespace std;
#define int long long

#define P 1000000007
void solve()
{
    int n,q,x;
    cin>>n;
    map<int,pair<int,int>>mp;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        mp[b]={a,c};
    }
    cin>>q;
    while(q--)
    {
        cin>>x;
        cout<<mp[x].first<<" "<<mp[x].second<<"\n";
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
