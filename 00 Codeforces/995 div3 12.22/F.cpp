#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<int,int>>a;
    a.push_back({m,m});
    for(int i=1;i<=q;i++)
    {
        int x;
        cin>>x;
        vector<pair<int,int>>b;
        for(auto [l,r]:a)
        {
            if(x<l) b.push_back({l-1,r});
            else if(x>r) b.push_back({l,r+1});
            else 
            {
                if(l!=r) b.push_back({l,r});
                b.push_back({1,1});
                b.push_back({n,n});
            }
        }
        sort(b.begin(),b.end());
        a.clear();
        for(auto [l,r]:b)
        {
            if(a.empty()||l>a.back().second)
            {
                a.push_back({l,r});
            }
            else
            {
                a.back().second=r;
            }
        }
        int ans=0;
        for(auto [l,r]:a) ans+=r-l+1;
        cout<<ans<<" ";
    }
    cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
