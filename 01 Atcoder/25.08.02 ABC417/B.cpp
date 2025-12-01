#include <bits/stdc++.h>
using namespace std;

void solve()
{
    multiset<int>st;
    int n,m;
    cin>>n>>m;
    while(n--)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    while(m--)
    {
        int x;
        cin>>x;
        if(st.count(x)) st.erase(st.find(x));
    }
    for(auto i:st) cout<<i<<" ";
    cout<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

