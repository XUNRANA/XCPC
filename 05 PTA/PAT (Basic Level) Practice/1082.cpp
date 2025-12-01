#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;
    set<pair<int,string>>st;
    while(n--)
    {
        string s;
        int a,b;
        cin>>s>>a>>b;
        st.insert({a*a+b*b,s});
    }
    cout<<st.begin()->second<<" "<<st.rbegin()->second<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
