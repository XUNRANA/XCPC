#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    int n,l,r;
    cin>>n>>l>>r>>s;
    int f=1;
    for(int i=l-1;i<=r-1;i++) if(s[i]!='o') f=0;
    if(f) cout<<"Yes\n";
    else cout<<"No\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

