#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    string s,t;
    getline(cin,s);
    getline(cin,t);
    map<char,int>c1,c2;
    set<char>st;
    for(auto i:s) c1[i]++;
    for(auto i:t) 
    {
        c2[i]++;
        st.insert(i);
    }
    int ans=0;
    for(auto i:st)
    {
        if(!c1.count(i)) c1[i]=0;
        // cout<<i<<" "<<c2[i]<<" "<<c1[i]<<"\n";
        ans+=max(c2[i]-c1[i],0ll);
    }
    // cout<<ans<<"\n";
    if(!ans) cout<<"Yes "<<s.size()-t.size()<<"\n";
    else cout<<"No "<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
