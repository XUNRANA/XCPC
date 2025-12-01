#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    int n,l,r;
    cin>>n>>l>>r>>s;
    for(int i=l;i<n-r;i++) cout<<s[i];
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

