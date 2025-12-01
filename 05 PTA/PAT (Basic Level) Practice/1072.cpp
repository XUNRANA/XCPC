#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;
    set<string>st;
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        st.insert(s);
    }
    int ans=0,res=0;
    for(int i=1;i<=n;i++)
    {
        string s;
        int k;
        cin>>s;
        cin>>k;
        vector<string>r;
        while(k--)
        {
            string t;
            cin>>t;
            if(st.count(t)) r.push_back(t);
        }
        if(r.size())
        {
            ans++;
            res+=r.size();
            cout<<s<<":";
            for(auto i:r) cout<<" "<<i;
            cout<<"\n";
        }
    }
    cout<<ans<<" "<<res<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
