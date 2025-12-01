#include <bits/stdc++.h>
using namespace std;
#define int long long



void solve()
{
    int n,m;
    cin>>n>>m;
    set<int>st;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    int p=-1;
    vector<int>d;
    for(auto i:st) 
    {
        if(p!=-1)
        {
            d.push_back(i-p);
        }
        p=i;
    }
    sort(d.begin(),d.end());
    int ans=0;
    
    // cout<<d.size()<<"?\n";
    // cout<<(int)d.size()+1-m<<"\n";
    for(int i=0;i<(int)d.size()+1-m;i++) ans+=d[i];
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}