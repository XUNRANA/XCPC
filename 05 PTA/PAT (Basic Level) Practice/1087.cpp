#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n;
    cin>>n;
    set<int>st;
    for(int i=1;i<=n;i++) 
    {
        int r=i/2+i/3+i/5;
        st.insert(r);
    }
    cout<<st.size()<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
