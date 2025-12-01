#include <bits/stdc++.h>
using namespace std;
#define int long long

int c[1010];
void solve()
{
    string s,t;
    getline(cin,s);
    getline(cin,t);
    set<char>st;
    for(auto i:s)
    {
        if(st.count(i)) continue;
        st.insert(i);
        cout<<i;
    }

    for(auto i:t)
    {
        if(st.count(i)) continue;
        st.insert(i);
        cout<<i;
    }

    // cout<<s<<"\n";
    // cout<<t<<"\n";

}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
