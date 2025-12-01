#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    string a,b;
    cin>>a>>b;
    for(auto &i:b) if(islower(i)) i=toupper(i);
    for(auto &i:a) if(islower(i)) i=toupper(i);
    // cout<<a<<"\n"<<b<<"\n";
    set<int>st;
    for(auto &i:b) st.insert(i);
    unordered_set<char>ans;
    for(auto i:a)
    {
        if(!st.count(i))
        {
            if(ans.count(i)) continue;
            ans.insert(i);
            cout<<i;
        }
    }
    // for(auto i:ans) cout<<i;
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

